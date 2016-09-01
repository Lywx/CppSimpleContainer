#pragma once

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

        Node(Node *prev, Node *next, const T& data);
        Node();
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

    List(const List& rhs);
    List& operator=(const List& rhs);

    List(List&& rhs);
    List& operator=(List&& rhs);

    ~List();

    Iterator begin();
    Iterator end();

    ConstIterator cbegin() const;
    ConstIterator cend() const;

    int size() const;
    bool empty() const;

    void clear();

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    void push_front(const T& x);
    void push_front(T&& x);

    void push_back(const T& x);
    void push_back(T&& x);

    T& pop_front();
    T& pop_back();

    Iterator insert(Iterator iterator, const T& x);
    Iterator insert(Iterator iterator, T&& x);

    void erase(Iterator iterator);
    void erase(Iterator from, Iterator to);

private:
    void init();

    Node *m_head;
    Node *m_tail;
    int   m_size;
};
