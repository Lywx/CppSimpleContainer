#include "Vector.h"

/************************************************************************/
/* Constructors and Destructor                                          */
/************************************************************************/
template <typename T>
Vector<T>::Vector(int capacity) :
    m_capacity(capacity),
    m_size(0)
{
    m_items = new T[m_capacity] { 0 };
}

template <typename T>
Vector<T>::Vector() : Vector(SPARE_CAPACITY)
{
}

template <typename T>
Vector<T>::Vector(const Vector& rhs) :
    m_capacity(rhs.m_capacity),
    m_size(rhs.m_size)
{
    m_items = new T[m_capacity] { 0 };

    for (auto i = 0; i < rhs.m_size; ++i)
    {
        m_items[i] = rhs.m_items[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    Vector<T> copy = rhs;
    swap(*this, copy);
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& rhs) noexcept :
    m_capacity(rhs.m_capacity),
    m_size(rhs.m_size),
    m_items(rhs.m_items)
{
    rhs.m_size = 0;
    rhs.m_capacity = 0;
    rhs.m_items = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& rhs) noexcept
{
    using std::swap;

    swap(m_size, rhs.m_size);
    swap(m_capacity, rhs.m_capacity);
    swap(m_items, rhs.m_items);

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_items;
}

/************************************************************************/
/* Public Members                                                       */
/************************************************************************/
template <typename T>
int Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
bool Vector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
T& Vector<T>::operator[](int idx)
{
    return at(idx);
}

template <typename T>
const T& Vector<T>::operator[](int idx) const
{
    return at(idx);
}

template <typename T>
T& Vector<T>::at(int idx)
{
    if (idx < m_size)
    {
        return m_items[idx];
    }
    else
    {
        throw std::out_of_range("Index is out of range.");
    }
}

template <typename T>
const T& Vector<T>::at(int idx) const
{
    if (idx < m_size)
    {
        return m_items[idx];
    }
    else
    {
        throw std::out_of_range("Index is out of range.");
    }
}

template <typename T>
void Vector<T>::push_back(T& item)
{
    if (m_size == m_capacity)
    {
        reserve(m_size * 2);
    }

    m_items[m_size++] = item;
}

template <typename T>
void Vector<T>::push_back(T&& item)
{
    if (m_size == m_capacity)
    {
        reserve(m_size * 2);
    }

    m_items[m_size++] = std::move(item);
}

template <typename T>
void Vector<T>::pop_back()
{
    --m_size;
}

template <typename T>
const T& Vector<T>::back() const
{
    return at(m_size - 1);
}

template <typename T>
const T& Vector<T>::front() const
{
    return at(0);
}

template <typename T>
void Vector<T>::assign()
{
// TODO
}

template <typename T>
void Vector<T>::clear()
{
    m_size = 0;
}

template <typename T>
void Vector<T>::reserve(int capacity)
{
    using std::swap;

    if (capacity > m_capacity)
    {
        auto *itemsNew = new T[capacity] { 0 };
        for (auto i = 0; i < size(); ++i)
        {
            itemsNew[i] = std::move(m_items[i]);
        }

        m_capacity = capacity;
        swap(m_items, itemsNew);
        delete[] itemsNew;
    }
}

template <typename T>
void Vector<T>::resize(int size)
{
    if (size > m_capacity)
    {
        reserve(size * 2);
    }

    m_size = size;
}

template <typename T>
void Vector<T>::resize(int size, const T& value)
{
    if (size > m_capacity)
    {
        reserve(size * 2);
    }
    else
    {
        if (size > m_size)
        {
            for (auto i = m_size; i < m_size - 1; ++i)
            {
                at(i) = value;
            }
        }
    }

    m_size = size;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return &m_items[0];
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return &m_items[0];
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return &m_items[m_size];
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return &m_items[m_size];
}
