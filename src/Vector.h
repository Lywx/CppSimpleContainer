#pragma once

#include <stdexcept>

template <typename T>
class Vector
{
public:
    typedef const T *const_iterator;
    typedef T *iterator;

    /************************************************************************/
    /* Constructors and Destructor                                          */
    /************************************************************************/
    explicit Vector(int capacity);
    explicit Vector();

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

    T&       operator[](int idx);
    const T& operator[](int idx) const;
    T&       at(int idx);
    const T& at(int idx) const;

    void push_back(T& item);
    void push_back(T&& item);
    void pop_back();
    const T& back() const;
    const T& front() const;

    void assign();
    void clear();
    void reserve(int capacity);
    void resize(int size);
    void resize(int size, const T& value);

    iterator begin();
    const_iterator cbegin() const;

    iterator end();
    const_iterator cend() const;

private:
    static const int SPARE_CAPACITY = 1;

    int m_capacity;
    int m_size;
    T  *m_items;
};