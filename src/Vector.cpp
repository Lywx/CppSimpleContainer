#include "Vector.h"

template <typename T>
Vector<T>::Vector(int size) :
    m_capacity(size),
    m_size(size)
{
    m_items = new T[m_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& rhs) :
    m_capacity(rhs.m_capacity),
    m_size(rhs.m_size)
{
    m_items = new T[m_capacity];

    for (auto i = 0; i < rhs.m_size; ++i)
    {
        m_items[i] = rhs.m_items[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    auto copy(rhs);

    // TODO
    swap(*this, copy);
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_items;
}

template <typename T>
T& Vector<T>::operator[](int idx)
{
    // TODO
}

template <typename T>
T& Vector<T>::at(int idx)
{
    // TODO
}

template <typename T>
int Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
void Vector<T>::reserve(int capacity)
{
    // TODO
}

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
bool Vector<T>::empty() const
{
    return size() == 0;
}
