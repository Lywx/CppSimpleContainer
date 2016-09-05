#include "List.h"

/************************************************************************/
/* Node Implementation                                                  */
/************************************************************************/
template <typename T>
List<T>::Node::Node(Node *prev, Node *next, const T& data) :
    prev(prev),
    next(next),
    data(data)
{
}

template <typename T>
List<T>::Node::Node(Node *prev, Node *next, const T&& data) :
    prev(prev),
    next(next),
    data(std::move(data))
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
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++() const
{
    m_current = m_current->next;
    return *this;
}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++(int) const
{
    // Call copy constructor
    auto old = *this;
    ++(*this);
    return old;
}

template <typename T>
bool List<T>::ConstIterator::operator==(ConstIterator& rhs) const
{
    return m_current == rhs.m_current;
}

template <typename T>
bool List<T>::ConstIterator::operator!=(ConstIterator& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
T& List<T>::ConstIterator::retrieve() const
{
    return m_current->data;
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
List<T>& List<T>::operator=(const List rhs)
{
    // I believe there is an error in Data Structures and Algorithm Analysis in
    // C++.
    using std::swap;
    swap(*this, rhs);
    return *this;
}

template <typename T>
List<T>::List(List&& rhs) noexcept
{
    // TODO
}

template <typename T>
List<T>& List<T>::operator=(List&& rhs) noexcept
{
    // TODO
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
    insert(back(), item);
}

template <typename T>
void List<T>::push_back(T&& item)
{
    insert(back(), std::move(item));
}

template <typename T>
T& List<T>::pop_front()
{
    auto itemReturn = front();
    erase(begin());
    return itemReturn;
}

template <typename T>
T& List<T>::pop_back()
{
    auto itemReturn = back();
    erase(--end());
    return itemReturn;
}

template <typename T>
typename List<T>::Iterator List<T>::insert(Iterator iterator, const T& item)
{
    Node *nodeCurrent = iterator.current;
    Node *nodeNew = new Node(nodeCurrent->prev, nodeCurrent, item);
    nodeCurrent->prev = nodeCurrent->prev->next = nodeNew;

    ++m_size;

    return nodeNew;
}

template <typename T>
typename List<T>::Iterator List<T>::insert(Iterator iterator, T&& item)
{
    Node *nodeCurrent = iterator.m_current;
    Node *nodeNew = new Node(nodeCurrent->prev, nodeCurrent, std::move(item));
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
    m_head->next = m_tail;
    m_tail = new Node;
    m_tail->prev = m_head;
}
