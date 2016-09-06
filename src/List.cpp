#include "List.h"

/************************************************************************/
/* Node Implementation                                                  */
/************************************************************************/
template <typename T>
List<T>::Node::Node(const T& item, Node *prev, Node *next) :
    prev(prev),
    next(next),
    item(item)
{
}

template <typename T>
List<T>::Node::Node(const T&& item, Node *prev, Node *next) :
    prev(prev),
    next(next),
    item(std::move(item))
{
}

/************************************************************************/
/* ConstIterator Implementation                                         */
/************************************************************************/
template <typename T>
List<T>::ConstIterator::ConstIterator() : m_current(nullptr)
{
}

template <typename T>
List<T>::ConstIterator::ConstIterator(Node *current) : m_current(current)
{
}

template <typename T>
List<T>::ConstIterator::~ConstIterator()
{

}

template <typename T>
const T& List<T>::ConstIterator::operator*() const
{
    return retrieve();
}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
    m_current = m_current->next;
    return *this;
}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++(int)
{
    // Call copy constructor
    auto old = *this;
    ++(*this);
    return old;
}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
    m_current = m_current->prev;
}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator--(int)
{
    auto old = *this;
    --(*this);
    return old;
}

template <typename T>
bool List<T>::ConstIterator::operator==(ConstIterator& rhs) const
{
    return m_current == rhs.m_current;
}

template <typename T>
bool List<T>::ConstIterator::operator==(ConstIterator&& rhs) const
{
    return m_current == rhs.m_current;
}

template <typename T>
bool List<T>::ConstIterator::operator!=(ConstIterator& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
bool List<T>::ConstIterator::operator!=(ConstIterator&& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
T& List<T>::ConstIterator::retrieve() const
{
    return m_current->item;
}

template <typename T>
T& List<T>::Iterator::operator*() const
{
    return ConstIterator::retrieve();
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
    ConstIterator::m_current = ConstIterator::m_current->next;
    return *this;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++(int)
{
    auto old = *this;
    ++(*this);
    return old;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
    ConstIterator::m_current = ConstIterator::m_current->prev;
    return *this;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--(int)
{
    auto old = *this;
    --(*this);
    return old;
}

/************************************************************************/
/* Iterator Implementation                                              */
/************************************************************************/
template <typename T>
List<T>::Iterator::Iterator(Node *current) : ConstIterator(current)
{
}

/************************************************************************/
/* List Implementation                                                  */
/************************************************************************/
template <typename T>
List<T>::List()
{
    init();
}

template <typename T>
List<T>::List(const List& rhs)
{
    init();

    for (auto& item : rhs)
    {
        push_back(item);
    }
}

template <typename T>
List<T>& List<T>::operator=(const List& rhs)
{
    // Initialization call copy constructor here
    List copy = rhs;

    using std::swap;
    swap(*this, copy);
    return *this;
}

template <typename T>
List<T>::List(List&& rhs) noexcept :
    m_head(rhs.m_head),
    m_tail(rhs.m_tail),
    m_size(rhs.m_size)
{
    rhs.m_size = 0;
    rhs.m_head = nullptr;
    rhs.m_tail = nullptr;
}

template <typename T>
List<T>& List<T>::operator=(List&& rhs) noexcept
{
    // Call move constructor here

    using std::swap;
    swap(m_head, rhs.m_head);
    swap(m_tail, rhs.m_tail);
    swap(m_size, rhs.m_size);

    return *this;
}

template <typename T>
List<T>::~List()
{
    clear();

    delete m_head;
    delete m_tail;
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    return m_head->next;
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    return m_tail;
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{
    return m_head->next;
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return m_tail;
}

template <typename T>
int List<T>::size() const
{
    return m_size;
}

template <typename T>
bool List<T>::empty() const
{
    return size() == 0;
}

template <typename T>
void List<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template <typename T>
T& List<T>::front()
{
    return *begin();
}

template <typename T>
const T& List<T>::front() const
{
    return *begin();
}

template <typename T>
T& List<T>::back()
{
    return *--end();
}

template <typename T>
const T& List<T>::back() const
{
    return *--end();
}

template <typename T>
void List<T>::push_front(const T& item)
{
    insert(begin(), item);
}

template <typename T>
void List<T>::push_front(T&& item)
{
    insert(begin(), std::move(item));
}

template <typename T>
void List<T>::push_back(const T& item)
{
    insert(end(), item);
}

template <typename T>
void List<T>::push_back(T&& item)
{
    insert(end(), std::move(item));
}

template <typename T>
T List<T>::pop_front()
{
    T itemReturn = front();
    erase(begin());
    return itemReturn;
}

template <typename T>
T List<T>::pop_back()
{
    T itemReturn = back();
    erase(--end());
    return itemReturn;
}

template <typename T>
typename List<T>::Iterator List<T>::insert(Iterator iterator, const T& item)
{
    Node *nodeCurrent = iterator.m_current;

    Node *nodeNew = new Node(item, nodeCurrent->prev, nodeCurrent);
    nodeCurrent->prev = nodeCurrent->prev->next = nodeNew;

    ++m_size;

    return nodeNew;
}

template <typename T>
typename List<T>::Iterator List<T>::insert(Iterator iterator, T&& item)
{
    Node *nodeCurrent = iterator.m_current;
    Node *nodeNew = new Node(std::move(item), nodeCurrent->prev, nodeCurrent);
    nodeCurrent->prev = nodeCurrent->prev->next = nodeNew;

    ++m_size;

    return nodeNew;
}

template <typename T>
typename List<T>::Iterator List<T>::erase(Iterator iterator)
{
    Node *nodeCurrent = iterator.m_current;
    Iterator iteratorReturn{ nodeCurrent->next };

    nodeCurrent->prev->next = nodeCurrent->next;
    nodeCurrent->next->prev = nodeCurrent->prev;

    delete nodeCurrent;
    --m_size;

    return iteratorReturn;
}

template <typename T>
typename List<T>::Iterator List<T>::erase(Iterator from, Iterator to)
{
    for (auto iterator = from; iterator != to();)
    {
        iterator = erase(iterator);
    }

    return to;
}

template <typename T>
void List<T>::init()
{
    m_size = 0;
    m_head = new Node;
    m_tail = new Node;

    m_tail->prev = m_head;
    m_head->next = m_tail;
}
