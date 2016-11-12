#include "catch.hpp"

#include <BinaryHeap.cpp>
#include <iostream>

using namespace std;

TEST_CASE("Binary Heap Test", "")
{
    SECTION("push, size, top")
    {
        auto heap = BinaryHeap<int>(10);
        heap.push(3);

        REQUIRE(heap.top() == 3);

        heap.push(2);

        REQUIRE(heap.top() == 2);

        heap.push(1);

        REQUIRE(heap.top() == 1);

        heap.push(4);

        REQUIRE(heap.top() == 1);

        heap.push(5);

        REQUIRE(heap.top() == 1);

        heap.push(9);

        REQUIRE(heap.top() == 1);
    }

    SECTION("empty, pop, size")
    {
        auto heap = BinaryHeap<int>(10);
        heap.push(3);
        heap.push(2);
        heap.push(1);

        int i = 0;
        int valueSequence[] = { 1, 2, 3 };
        while(heap.size() != 0)
        {
            int value = heap.top();
            heap.pop();

            REQUIRE(value == valueSequence[i]);

            ++i;
        }

        REQUIRE(heap.empty());
    }

    SECTION("capacity, reserve")
    {
        auto heap = BinaryHeap<int>(10);
        REQUIRE(heap.capacity() == 10);

        heap.reserve(20);
        REQUIRE(heap.capacity() == 20);

        heap.reserve(30);
        REQUIRE(heap.capacity() == 30);
    }
}