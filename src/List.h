#pragma once

#include <utility>

// List is an ADT for double linked list.
template<typename T>
class List
{
    /************************************************************************/
    /* Inner Class Declaration                                              */
    /************************************************************************/
private:
    struct Node;
public:
    class const_iterator
    {
    protected:
        const_iterator();

        // Allow implicit conversion from Node*
        const_iterator(Node *current);
    public:
        ~const_iterator();

        const T& operator*() const;

        // Prefix
        const_iterator& operator++();
        const_iterator& operator--();

        // Postfix and notice that postfix return copy of iterator
        const_iterator operator++(int);
        const_iterator operator--(int);

        bool operator==(const_iterator& rhs) const;
        bool operator==(const_iterator&& rhs) const;
        bool operator!=(const_iterator& rhs) const;
        bool operator!=(const_iterator&& rhs) const;

    protected:
        T& retrieve() const;

        Node *m_current;

        friend class List;
    };

    class iterator : public const_iterator
    {
    public:
        // Allow implicit conversion
        iterator(Node *current);

        T& operator*() const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator& operator--(int);

        friend class List;
    };

private:
    struct Node
    {
        Node *prev;
        Node *next;
        T     item;

        Node(const T& item = {}, Node *prev = nullptr, Node *next = nullptr);
        Node(const T && item, Node *prev = nullptr, Node *next = nullptr);
    };

public:
    /************************************************************************/
    /* Class Declaration                                                    */
    /************************************************************************/
    List();

    // Copy Semantics
    List(const List& rhs);
    List& operator=(const List& rhs);

    // Move Semantics
    List(List&& rhs) noexcept;
    List& operator=(List&& rhs) noexcept;

    ~List();

    // First iterator after head
    iterator begin();
    const_iterator begin() const;

    // Iterator for tail
    iterator end();
    const_iterator end() const;

    // First iterator after head
    const_iterator cbegin() const;

    // Iterator for tail
    const_iterator cend() const;

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

    T pop_front();
    T pop_back();

    // Insert item before iterator
    iterator insert(iterator iter, const T& item);
    iterator insert(iterator iter, T&& item);

    iterator erase(iterator iterator);
    iterator erase(iterator from, iterator to);

private:
    void init();

    Node *m_head;
    Node *m_tail;
    int   m_size;

    friend void swap(List& lhs, List& rhs) noexcept
    {
        using std::swap;

        // Swap the pointers so they are swapping the pointed nodes
        swap(lhs.m_head, rhs.m_head);
        swap(lhs.m_tail, rhs.m_tail);

        swap(lhs.m_size, rhs.m_size);
    }
};