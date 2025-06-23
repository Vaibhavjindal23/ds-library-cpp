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

#include <iostream>
#include <cassert>
#include "../data_structures/stack.hpp"

using namespace data_structures;

/**
 * @brief Test pushing and checking size.
 */
void test_push_and_size() {
    Stack<int> s;
    assert(s.empty());
    s.push(10);
    s.push(20);
    s.push(30);
    assert(!s.empty());
    assert(s.size() == 3);
    std::cout << "[PASS] test_push_and_size()\n";
}

/**
 * @brief Test top() getter and const correctness.
 */
void test_top() {
    Stack<std::string> s;
    s.push("Hello");
    s.push("World");
    assert(s.top() == "World");

    s.top() = "Modified";
    assert(s.top() == "Modified");

    const Stack<std::string>& cs = s;
    assert(cs.top() == "Modified");
    std::cout << "[PASS] test_top()\n";
}

/**
 * @brief Test popping elements and underflow exception.
 */
void test_pop_and_underflow() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    assert(s.top() == 2);
    s.pop();
    s.pop();
    assert(s.empty());

    // Should throw underflow error
    try {
        s.pop();
        assert(false); // This should not be reached
    } catch (const std::underflow_error& e) {
        std::cout << "[PASS] test_pop_and_underflow()\n";
    }
}

/**
 * @brief Test clear operation.
 */
void test_clear() {
    Stack<double> s;
    s.push(1.1);
    s.push(2.2);
    s.push(3.3);
    assert(s.size() == 3);
    s.clear();
    assert(s.empty());
    std::cout << "[PASS] test_clear()\n";
}

/**
 * @brief Test print functionality.
 */
void test_print() {
    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    std::cout << "[INFO] Expect: C B A → ";
    s.print();
    std::cout << "[PASS] test_print()\n";
}

/**
 * @brief Prints the result of each test case.
 * @param name Name of the test case.
 * @param passed Boolean indicating if test passed.
 */
void print_test_result(const std::string& name, bool passed) {
    std::cout << (passed ? "[PASS] " : "[FAIL] ") << name << "\n";
}

/**
 * @brief Tests the at() function for both const and non-const access,
 *        and verifies that out-of-range indices throw exceptions.
 */
void test_at() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30); // Stack top is 30

    // Check valid accesses
    assert(s.at(0) == 30);
    assert(s.at(1) == 20);
    assert(s.at(2) == 10);

    // Check out-of-range throws exception
    bool caught = false;
    try {
        s.at(3);
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    // Test const version of at()
    const Stack<int>& cs = s;
    assert(cs.at(0) == 30);

    print_test_result("at()", true);
}

/**
 * @brief Tests bottom() accessor in both const and non-const contexts,
 *        including exception when stack is empty.
 */
void test_bottom() {
    Stack<int> s;
    s.push(5);
    s.push(15);
    s.push(25);

    // Verify bottom element access
    assert(s.bottom() == 5);

    const Stack<int>& cs = s;
    assert(cs.bottom() == 5);

    // Clear stack and test that bottom() throws underflow error
    s.clear();
    bool caught = false;
    try {
        s.bottom();
    } catch (const std::underflow_error&) {
        caught = true;
    }
    assert(caught);

    print_test_result("bottom()", true);
}

/**
 * @brief Tests swapping contents of two stacks, ensuring elements swap correctly.
 */
void test_swap() {
    Stack<int> s1, s2;
    s1.push(1);
    s1.push(2);

    s2.push(10);
    s2.push(20);
    s2.push(30);

    s1.swap(s2);

    // After swap, s1 should have s2's elements and vice versa
    assert(s1.size() == 3 && s1.top() == 30);

    print_test_result("swap()", true);
}

/**
 * @brief Tests the equality operator== for stacks.
 *        Ensures equality only if stacks have identical elements in the same order.
 */
void test_equality_operator() {
    Stack<int> s1, s2;

    // Empty stacks are equal
    assert(s1 == s2);

    s1.push(100);
    // Different sizes -> not equal
    assert(!(s1 == s2));

    s2.push(100);
    // Same elements -> equal
    assert(s1 == s2);

    s1.push(200);
    s2.push(300);
    // Different elements -> not equal
    assert(!(s1 == s2));

    s2.pop();
    s2.push(200);
    // Same elements again -> equal
    assert(s1 == s2);

    print_test_result("operator==", true);
}

void test_reverse() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3); // top = 3, bottom = 1

    s.reverse();

    // After reverse, top should be old bottom, bottom should be old top
    assert(s.top() == 1);
    assert(s.bottom() == 3);

    // Verify order after reverse
    assert(s.at(0) == 1);
    assert(s.at(1) == 2);
    assert(s.at(2) == 3);

    print_test_result("reverse()", true);
}

/**
 * @brief Entry point for stack testing.
 */
int main() {
    std::cout << "========== Stack Tests ==========\n";

    test_push_and_size();
    test_top();
    test_pop_and_underflow();
    test_clear();
    test_print();
    test_at();
    test_bottom();
    test_swap();
    test_equality_operator();
    test_reverse();

    std::cout << "All tests completed successfully.\n";
    return 0;
}
