#pragma once
#include<vector>

template <typename T>
class Vector
{
public:
    explicit Vector(int size);

    // Copy Operations
    Vector(const Vector& rhs);
    Vector& operator=(const Vector& rhs);

    ~Vector();

    T& operator[](int idx);
    T& at(int idx);
    int capacity() const;
    void reserve(int capacity);

    // TODO
    void push_back(T x);
    void pop_back();
    const T& back() const;
    const T& front() const;

    void assign();
    void clear();

    int  size() const;
    bool empty() const;

private:
    int m_capacity;
    int m_size;
    T  *m_items;
};


