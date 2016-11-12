#include "BinaryHeap.h"

#include <algorithm>
#include <stdexcept>

/************************************************************************/
/* Constructors and Destructor                                          */
/************************************************************************/
template <typename T>
BinaryHeap<T>::BinaryHeap(int capacity) :
    m_capacity(capacity),
    m_size(0),
    m_items(nullptr)
{
    m_items = new T[capacity + EXTRA_CAPACITY];
}

template <typename T>
BinaryHeap<T>::~BinaryHeap()
{
    delete m_items;
}

template <typename T>
void BinaryHeap<T>::push(T item)
{
    using std::swap;

    if (m_size == m_capacity)
    {
        reserve(m_size * 2);
    }

    int indexLast = ++m_size;
    m_items[indexLast] = item;

    for (int index = indexLast; index > 1 && m_items[index] < m_items[index / 2]; index /= 2)
    {
        swap(m_items[index], m_items[index / 2]);
    }

    //// Alternative approach for the above loop for readability
    // for (int index = indexLast; index > 1; index /= 2)
    // {
    //     T& value = m_items[index];
    //     T& valueParent = m_items[index / 2];
    //     if (value < valueParent)
    //     {
    //         swap(value, valueParent);
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
}

template <typename T>
void BinaryHeap<T>::pop()
{
    // Remember that the index starts from 1
    m_items[1] = m_items[m_size--];

    percolate_down(1);
}

template <typename T>
const T& BinaryHeap<T>::top() const
{
    return m_items[1];
}

template <typename T>
T& BinaryHeap<T>::top()
{
    if (m_size == 0)
    {
        throw std::underflow_error("The heap is empty.");
    }

    return m_items[1];
}

template <typename T>
int BinaryHeap<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
bool BinaryHeap<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
int BinaryHeap<T>::size() const
{
    return m_size;
}

template <typename T>
void BinaryHeap<T>::reserve(int capacity)
{
    using std::swap;

    if (capacity > m_capacity)
    {
        auto *itemsNew = new T[capacity + EXTRA_CAPACITY] { 0 };

        // Valid item index starts from 1
        for (auto i = 1; i <= size(); ++i)
        {
            itemsNew[i] = std::move(m_items[i]);
        }

        m_capacity = capacity;
        swap(m_items, itemsNew);
        delete[] itemsNew;
    }
}

/************************************************************************/
/* Private Members                                                      */
/************************************************************************/
#if DEBUG
#include <iostream>
using namespace std;
#endif

template <typename T>
void BinaryHeap<T>::percolate_down(int index)
{
    using std::swap;

    int indexSmallerChild;

    for (; index * 2 <= m_size; index = indexSmallerChild)
    {
        indexSmallerChild = index * 2;
        if (indexSmallerChild < m_size

                // Find the smaller value in 2 children
                && m_items[indexSmallerChild + 1] < m_items[indexSmallerChild])
        {
            ++indexSmallerChild;
        }

        if (m_items[indexSmallerChild] < m_items[index])
        {
            swap(m_items[index], m_items[indexSmallerChild]);
        }
        else
        {
            break;
        }
    }
}

