#pragma once

#include <utility>

// List is an ADT for double linked list.
template<typename T>
class List
{
private:
    /************************************************************************/
    /* Inner Class Definition                                               */
    /************************************************************************/
    struct Node
    {
        Node *prev;
        Node *next;
        T     data;

        Node(Node *prev = nullptr, Node *next = nullptr, const T& data = {});
        Node(Node *prev = nullptr, Node *next = nullptr, const T && data = {});
    };

    class ConstIterator
    {
    protected:
        ConstIterator();
        explicit ConstIterator(Node *current);
    public:
        ~ConstIterator();

        const T& operator*() const;

        ConstIterator& operator++() const;
        ConstIterator& operator++(int) const;

        bool operator==(ConstIterator& rhs) const;
        bool operator!=(ConstIterator& rhs) const;

    protected:
        T& retrieve() const;

        Node *m_current;

        friend class List;
    };

    class Iterator : public ConstIterator
    {
    public:
        explicit Iterator(Node *current);

        T& operator*() const;
        Iterator& operator++();
        Iterator& operator++(int);

        friend class List;
    };

public:
    /************************************************************************/
    /* Class Definition                                                     */
    /************************************************************************/
    List();

    // Copy Semantics
    List(const List& rhs);
    List& operator=(const List rhs);

    // Move Semantics
    List(List&& rhs) noexcept;
    List& operator=(List&& rhs) noexcept;

    ~List();

    // First iterator after head
    Iterator begin();

    // Iterator for tail
    Iterator end();

    // First iterator after head
    ConstIterator cbegin() const;

    // Iterator for tail
    ConstIterator cend() const;

    int  size() const;
    bool empty() const;

    void clear();

    // First item after head
    T& front();
    const T& front() const;

    // Last item before tail
    T& back();
    const T& back() const;

    void push_front(const T& item);
    void push_front(T&& item);

    void push_back(const T& item);
    void push_back(T&& item);

    T& pop_front();
    T& pop_back();

    // Insert item before iterator
    Iterator insert(Iterator iterator, const T& item);
    Iterator insert(Iterator iterator, T&& item);

    Iterator erase(Iterator iterator);
    Iterator erase(Iterator from, Iterator to);

private:
    void init();

    Node *m_head;
    Node *m_tail;
    int   m_size;

    friend void swap(List& lhs, List& rhs)
    {
        using std::swap;

        // Swap the pointers so they are swapping the pointed nodes
        swap(lhs.m_head, rhs.m_head);
        swap(lhs.m_tail, rhs.m_tail);

        swap(lhs.m_size, rhs.m_size);
    }
};