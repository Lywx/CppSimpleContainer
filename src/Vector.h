#pragma once

#include <stdexcept>

template <typename T>
class Vector
{
public:
    /************************************************************************/
    /* Constructors and Destructor                                          */
    /************************************************************************/
    explicit Vector(int size);

    // Copy Semantics
    Vector(const Vector& rhs);
    Vector& operator=(const Vector& rhs);

    // Move Semantics
    Vector(Vector&& rhs) noexcept;
    Vector& operator=(Vector&& rhs) noexcept;

    ~Vector();

    /************************************************************************/
    /* Public Members                                                       */
    /************************************************************************/
    int  capacity() const;
    int  size() const;
    bool empty() const;

    T& operator[](int idx);
    T& at(int idx);

    void push_back(T x);
    void pop_back();
    const T& back() const;
    const T& front() const;

    void assign();
    void clear();
    void reserve(int capacity);

private:
    int m_capacity;
    int m_size;
    T  *m_items;
};