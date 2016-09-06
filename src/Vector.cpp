#include "Vector.h"

/************************************************************************/
/* Constructors and Destructor                                          */
/************************************************************************/
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
    return size() == 0;
}

template <typename T>
T& Vector<T>::operator[](int idx)
{
    return at(idx);
}

template <typename T>
T& Vector<T>::at(int idx)
{
    if (idx < size())
    {
        return m_items[idx];
    }
    else
    {
        throw std::out_of_range("Index is out of range.");
    }
}

template <typename T>
void Vector<T>::push_back(T x)
{
// TODO
}

template <typename T>
void Vector<T>::pop_back()
{
// TODO
}

template <typename T>
const T& Vector<T>::back() const
{
// TODO
}

template <typename T>
const T& Vector<T>::front() const
{
// TODO
}

template <typename T>
void Vector<T>::assign()
{
// TODO
}

template <typename T>
void Vector<T>::clear()
{
// TODO
}

template <typename T>
void Vector<T>::reserve(int capacity)
{
    // TODO
}

