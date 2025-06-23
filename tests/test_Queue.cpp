/**
 * @author      Vaibhav Jindal
 *              B.Tech CSE Core, VIT Bhopal
 * 
 * @details     Modular, templated C++ library for 
 *              educational, research, and production use.
 * 
 * 📦 Namespace: data_structures
 * 📧 Contact  : jindalvaibhav63@gmail.com
 */

#include "../data_structures/Queue.hpp"
#include <iostream>
#include <string>

using namespace data_structures;

void test_basic_enqueue_dequeue() {
    std::cout << "[Test] Basic enqueue/dequeue\n";
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    if (q.front() != 10) std::cerr << "FAILED: Expected front 10\n";
    if (q.back() != 30) std::cerr << "FAILED: Expected back 30\n";

    q.dequeue();
    if (q.front() != 20) std::cerr << "FAILED: Expected front 20 after dequeue\n";

    q.dequeue();
    q.dequeue();

    if (!q.empty()) std::cerr << "FAILED: Queue should be empty after 3 dequeues\n";

    std::cout << "Passed\n\n";
}

void test_resize_behavior() {
    std::cout << "[Test] Resizing behavior\n";
    Queue<int> q;
    for (int i = 0; i < 1000; ++i) {
        q.enqueue(i);
    }

    if (q.front() != 0 || q.back() != 999)
        std::cerr << "FAILED: Unexpected front or back after resize\n";

    for (int i = 0; i < 500; ++i) {
        q.dequeue();
    }

    if (q.front() != 500)
        std::cerr << "FAILED: Front should be 500 after 500 dequeues\n";

    std::cout << "Passed\n\n";
}

void test_clear_functionality() {
    std::cout << "[Test] Clear functionality\n";
    Queue<std::string> q;
    q.enqueue("apple");
    q.enqueue("banana");
    q.clear();

    if (!q.empty()) std::cerr << "FAILED: Queue should be empty after clear\n";

    try {
        q.front();
        std::cerr << "FAILED: front() should throw after clear\n";
    } catch (...) {
        std::cout << "Passed\n\n";
    }
}

void test_exception_on_empty_access() {
    std::cout << "[Test] Exception safety on empty queue\n";
    Queue<int> q;

    try {
        q.front();
        std::cerr << "FAILED: front() on empty should throw\n";
    } catch (...) {}

    try {
        q.back();
        std::cerr << "FAILED: back() on empty should throw\n";
    } catch (...) {}

    try {
        q.dequeue();
        std::cerr << "FAILED: dequeue() on empty should throw\n";
    } catch (...) {}

    std::cout << "Passed\n\n";
}

void test_data_integrity() {
    std::cout << "[Test] Data integrity under rotation\n";
    Queue<int> q;
    for (int i = 1; i <= 10; ++i) q.enqueue(i);  // Fill
    for (int i = 1; i <= 5; ++i) q.dequeue();    // Rotate
    for (int i = 11; i <= 15; ++i) q.enqueue(i); // Wrap around

    int expected = 6;
    while (!q.empty()) {
        if (q.front() != expected) {
            std::cerr << "FAILED: Expected " << expected << ", got " << q.front() << "\n";
        }
        q.dequeue();
        ++expected;
    }
    std::cout << "Passed\n\n";
}

int main() {
    std::cout << "=== Queue<T> Test Suite ===\n\n";

    test_basic_enqueue_dequeue();
    test_resize_behavior();
    test_clear_functionality();
    test_exception_on_empty_access();
    test_data_integrity();

    std::cout << "All tests completed.\n";
    return 0;
}
