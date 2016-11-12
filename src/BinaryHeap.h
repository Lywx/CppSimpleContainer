#pragma once

// Summary: Min heap based priority queue.
// Reference: 俞勇 数据结构_ 思想与实现, 1st, 2009
// Implementation: DONE.
template <typename T>
class BinaryHeap
{
public:
    BinaryHeap(int capacity);
    ~BinaryHeap();

    void     push(T item);
    void     pop();

    const T& top() const;
    T&       top();

    int      size() const;
    int      capacity() const;
    bool     empty() const;

    void     reserve(int capacity);

private:
    static const int EXTRA_CAPACITY = 1;

    void     percolate_down(int index);

    // Remark: Because the indexes start from 1, the capacity means the maximum
    // valid item size in current "m_items".
    int m_capacity;
    int m_size;

    // Remark: Valid items' indexes start from 1.
    T  *m_items;
};
