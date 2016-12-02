Summary
==

A simple implementation of C++ Standard Library containers for study rather than 
production. All the data structures are provided with iterator support, but 
currently have no plan to support allocator.

Linear Data Structure:

1. Vector
2. List
3. Queue (TODO)
4. Stack (TODO)
5. Binary Heap (Priority Queue)
6. Hash Map (TODO)

Tree Data Structure:

1. Binary Tree (TODO)
2. N-nary Tree (TODO)
3. Binary Search Tree
4. AVL Tree (TODO)
5. Black-red Tree (TODO)
6. AA Tree (TODO)
7. Segment Tree (Range Minimum Query) (TODO)
8. Trie (TODO)

Graph Data Structure:

(TODO)

Physical Design
==

Though most (if not all) of containers classes are template classes, I still
separate the header and implementation in different files for cleaner interface.

Reference
==

Most of the work can
be referred to:

1. Weiss M. A., *Data Structures and Algorithm Analysis in C++*.
2. Luis Sempe, *User Interface Programming for Games*.
3. 俞勇, *数据结构 思想与实现*.
4. Microsoft, *Visual C++ Standard Template Library*.
5. SGI, *Standard Template Library*, http://www.sgi.com/tech/stl/.