#include "List.h"

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
List<T>::List() :
    m_head(Node()),
    m_tail(Node()),
    m_size(0)
{
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return m_head;
}

template <typename T>
typename List<T>::Iterator List<T>::end() const
{
    return m_tail;
}
