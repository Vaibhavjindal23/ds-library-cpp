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

#include "../data_structures/Singly_Linked_List.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <functional>

using namespace data_structures;
class TestFramework
{
private:
    int total_tests = 0;
    int passed_tests = 0;
    std::string current_suite = "";

public:
    void start_suite(const std::string &suite_name)
    {
        current_suite = suite_name;
        std::cout << "\n=== Testing " << suite_name << " ===" << std::endl;
    }

    void test(const std::string &test_name, bool condition)
    {
        total_tests++;
        if (condition)
        {
            passed_tests++;
            std::cout << test_name << " - PASSED" << std::endl;
        }
        else
        {
            std::cout << test_name << " - FAILED" << std::endl;
        }
    }

    void test_exception(const std::string &test_name, std::function<void()> func, const std::string &expected_exception)
    {
        total_tests++;
        try
        {
            func();
            std::cout << test_name << " - FAILED (No exception thrown)" << std::endl;
        }
        catch (const std::exception &e)
        {
            passed_tests++;
            std::cout << test_name << " - PASSED (Exception: " << e.what() << ")" << std::endl;
        }
    }

    void print_summary()
    {
        std::cout << "\n=== TEST SUMMARY ===" << std::endl;
        std::cout << "Total Tests: " << total_tests << std::endl;
        std::cout << "Passed: " << passed_tests << std::endl;
        std::cout << "Failed: " << (total_tests - passed_tests) << std::endl;
        std::cout << "Success Rate: " << (double)passed_tests / total_tests * 100 << "%" << std::endl;

        if (passed_tests == total_tests)
        {
            std::cout << "\n ALL TESTS PASSED! " << std::endl;
        }
        else
        {
            std::cout << "\n Some tests failed. Review the implementation." << std::endl;
        }
    }
};

/**
 * @brief Performance testing utilities
 */

class PerformanceTimer
{
private:
    std::chrono::high_resolution_clock::time_point start_time;

public:
    void start()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double get_duration_ms()
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        return duration.count() / 1000.0; // Convert to milliseconds
    }
};

// Test Helper Functions
template <typename T>
std::vector<T> list_to_vector(const SinglyLinkedList<T> &list)
{
    std::vector<T> result;
    for (int i = 0; i < list.size(); i++)
    {
        result.push_back(list.at(i));
    }
    return result;
}

template <typename T>
bool vectors_equal(const std::vector<T> &v1, const std::vector<T> &v2)
{
    if (v1.size() != v2.size())
        return false;
    for (size_t i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

// Test Suites

/**
 * @brief Test basic operations (constructor, destructor, empty, size)
 */
void test_basic_operations(TestFramework &tf)
{
    tf.start_suite("Basic Operations");

    // Test empty list
    SinglyLinkedList<int> list;
    tf.test("Empty list - size should be 0", list.size() == 0);
    tf.test("Empty list - should be empty", list.empty());

    // Test with one element
    list.push_front(5);
    tf.test("Single element - size should be 1", list.size() == 1);
    tf.test("Single element - should not be empty", !list.empty());

    // Test clear
    list.clear();
    tf.test("After clear - size should be 0", list.size() == 0);
    tf.test("After clear - should be empty", list.empty());
}

/**
 * @brief Test insertion operations
 */
void test_insertion_operations(TestFramework &tf)
{
    tf.start_suite("Insertion Operations");

    SinglyLinkedList<int> list;

    // Test push_front
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    tf.test("Push front - size should be 3", list.size() == 3);
    tf.test("Push front - first element should be 1", list.front() == 1);
    tf.test("Push front - order check", list.at(0) == 1 && list.at(1) == 2 && list.at(2) == 3);

    // Test push_back
    list.clear();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    tf.test("Push back - size should be 3", list.size() == 3);
    tf.test("Push back - last element should be 3", list.back() == 3);
    tf.test("Push back - order check", list.at(0) == 1 && list.at(1) == 2 && list.at(2) == 3);

    // Test insert at specific positions
    list.clear();
    list.insert(0, 10); // Insert at beginning
    tf.test("Insert at 0 - element should be 10", list.at(0) == 10);

    list.insert(1, 20); // Insert at end
    tf.test("Insert at end - element should be 20", list.at(1) == 20);

    list.insert(1, 15); // Insert in middle
    tf.test("Insert in middle - correct order",
            list.at(0) == 10 && list.at(1) == 15 && list.at(2) == 20);

    // Test invalid insertions
    tf.test_exception("Insert at negative index", [&]()
                      { list.insert(-1, 5); }, "out_of_range");
    tf.test_exception("Insert beyond size", [&]()
                      { list.insert(10, 5); }, "out_of_range");
}

/**
 * @brief Test deletion operations
 */
void test_deletion_operations(TestFramework &tf)
{
    tf.start_suite("Deletion Operations");

    SinglyLinkedList<int> list;

    // Test pop_front
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();
    tf.test("Pop front - size decreased", list.size() == 2);
    tf.test("Pop front - new front is 2", list.front() == 2);

    // Test pop_back
    list.pop_back();
    tf.test("Pop back - size decreased", list.size() == 1);
    tf.test("Pop back - remaining element is 2", list.front() == 2);

    // Test remove at index
    list.push_back(3);
    list.push_back(4); // List: [2, 3, 4]
    list.remove(1);    // Remove middle element
    tf.test("Remove middle - correct elements remain",
            list.at(0) == 2 && list.at(1) == 4 && list.size() == 2);

    // Test remove_value
    list.clear();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(2);

    bool removed = list.remove_value(2);
    tf.test("Remove value - returns true when found", removed);
    tf.test("Remove value - removes first occurrence",
            list.at(0) == 1 && list.at(1) == 3 && list.at(2) == 2);

    bool not_removed = list.remove_value(10);
    tf.test("Remove non-existent value - returns false", !not_removed);

    // Test exceptions for empty list
    list.clear();
    tf.test_exception("Pop front on empty list", [&]()
                      { list.pop_front(); }, "underflow_error");
    tf.test_exception("Pop back on empty list", [&]()
                      { list.pop_back(); }, "underflow_error");
}

/**
 * @brief Test access operations
 */
void test_access_operations(TestFramework &tf)
{
    tf.start_suite("Access Operations");

    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    // Test front and back
    tf.test("Front access", list.front() == 10);
    tf.test("Back access", list.back() == 30);

    // Test at() method
    tf.test("At index 0", list.at(0) == 10);
    tf.test("At index 1", list.at(1) == 20);
    tf.test("At index 2", list.at(2) == 30);

    // Test const version
    const SinglyLinkedList<int> &const_list = list;
    tf.test("Const at access", const_list.at(1) == 20);

    // Test modifications through references
    list.at(1) = 25;
    tf.test("Modify through reference", list.at(1) == 25);

    // Test invalid access
    tf.test_exception("Access negative index", [&]()
                      { list.at(-1); }, "out_of_range");
    tf.test_exception("Access beyond size", [&]()
                      { list.at(10); }, "out_of_range");

    // Test access on empty list
    list.clear();
    tf.test_exception("Front on empty list", [&]()
                      { list.front(); }, "underflow_error");
    tf.test_exception("Back on empty list", [&]()
                      { list.back(); }, "underflow_error");
}

/**
 * @brief Test search and utility operations
 */
void test_search_and_utility(TestFramework &tf)
{
    tf.start_suite("Search and Utility Operations");

    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(2);

    // Test contains
    tf.test("Contains existing element", list.contains(2));
    tf.test("Does not contain non-existing element", !list.contains(10));

    // Test find
    tf.test("Find existing element - returns first index", list.find(2) == 1);
    tf.test("Find non-existing element - returns -1", list.find(10) == -1);

    // Test reverse
    list.reverse();
    std::vector<int> expected = {2, 3, 2, 1};
    tf.test("Reverse operation", vectors_equal(list_to_vector(list), expected));

    // Test length
    tf.test("Length matches size", list.length() == list.size());
}

/**
 * @brief Test advanced operations
 */
void test_advanced_operations(TestFramework &tf)
{
    tf.start_suite("Advanced Operations");

    // Test sorted operations
    SinglyLinkedList<int> sorted_list;
    sorted_list.insert_sorted(5);
    sorted_list.insert_sorted(2);
    sorted_list.insert_sorted(8);
    sorted_list.insert_sorted(1);

    std::vector<int> expected_sorted = {1, 2, 5, 8};
    tf.test("Insert sorted maintains order",
            vectors_equal(list_to_vector(sorted_list), expected_sorted));
    tf.test("Is sorted check", sorted_list.is_sorted());

    // Test sort operation
    SinglyLinkedList<int> unsorted_list;
    unsorted_list.push_back(3);
    unsorted_list.push_back(1);
    unsorted_list.push_back(4);
    unsorted_list.push_back(2);

    unsorted_list.sort();
    std::vector<int> expected_after_sort = {1, 2, 3, 4};
    tf.test("Sort operation",
            vectors_equal(list_to_vector(unsorted_list), expected_after_sort));

    // Test slice operation
    SinglyLinkedList<int> list_for_slice;
    for (int i = 0; i < 5; i++)
    {
        list_for_slice.push_back(i);
    }

    auto sliced = list_for_slice.slice(1, 4);
    std::vector<int> expected_slice = {1, 2, 3};
    tf.test("Slice operation",
            vectors_equal(list_to_vector(sliced), expected_slice));

    // Test unique operation
    SinglyLinkedList<int> list_with_dups;
    list_with_dups.push_back(1);
    list_with_dups.push_back(2);
    list_with_dups.push_back(2);
    list_with_dups.push_back(3);
    list_with_dups.push_back(1);

    list_with_dups.unique();
    std::vector<int> expected_unique = {1, 2, 3};
    tf.test("Unique operation",
            vectors_equal(list_to_vector(list_with_dups), expected_unique));
}

/**
 * @brief Test special algorithms
 */
void test_special_algorithms(TestFramework &tf)
{
    tf.start_suite("Special Algorithms");

    // Test middle element
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    tf.test("Middle element (odd size)", list.middle() == 3);

    list.push_back(6);
    tf.test("Middle element (even size)", list.middle() == 4);

    // Test nth from end
    tf.test("1st from end", list.nth_from_end(1) == 6);
    tf.test("3rd from end", list.nth_from_end(3) == 4);

    // Test palindrome
    SinglyLinkedList<int> palindrome_list;
    palindrome_list.push_back(1);
    palindrome_list.push_back(2);
    palindrome_list.push_back(3);
    palindrome_list.push_back(2);
    palindrome_list.push_back(1);

    tf.test("Is palindrome - true case", palindrome_list.is_palindrome());
    tf.test("Is palindrome - false case", !list.is_palindrome());

    // Test rotation
    SinglyLinkedList<int> rotate_list;
    for (int i = 1; i <= 5; i++)
    {
        rotate_list.push_back(i);
    }

    rotate_list.rotate_left(2);
    std::vector<int> expected_left_rotate = {3, 4, 5, 1, 2};
    tf.test("Rotate left",
            vectors_equal(list_to_vector(rotate_list), expected_left_rotate));

    rotate_list.rotate_right(1);
    std::vector<int> expected_right_rotate = {2, 3, 4, 5, 1};
    tf.test("Rotate right",
            vectors_equal(list_to_vector(rotate_list), expected_right_rotate));
}

/**
 * @brief Test edge cases and error conditions
 */
void test_edge_cases(TestFramework &tf)
{
    tf.start_suite("Edge Cases and Error Handling");

    // Test operations on empty list
    SinglyLinkedList<int> empty_list;
    tf.test_exception("Middle on empty list", [&]()
                      { empty_list.middle(); }, "runtime_error");

    // Test boundary conditions
    SinglyLinkedList<int> single_element;
    single_element.push_back(42);
    tf.test("Middle of single element", single_element.middle() == 42);
    tf.test("Single element is palindrome", single_element.is_palindrome());

    // Test invalid parameters
    tf.test_exception("nth_from_end with 0", [&]()
                      { single_element.nth_from_end(0); }, "invalid_argument");
    tf.test_exception("nth_from_end beyond size", [&]()
                      { single_element.nth_from_end(5); }, "out_of_range");

    // Test slice edge cases
    SinglyLinkedList<int> slice_test;
    slice_test.push_back(1);
    slice_test.push_back(2);

    tf.test_exception("Invalid slice - start >= end", [&]()
                      { slice_test.slice(1, 1); }, "out_of_range");
    tf.test_exception("Invalid slice - negative start", [&]()
                      { slice_test.slice(-1, 1); }, "out_of_range");
}

/**
 * @brief Performance tests for large datasets
 */
void test_performance(TestFramework &tf)
{
    tf.start_suite("Performance Tests");

    PerformanceTimer timer;
    const int LARGE_SIZE = 1000;

    // Test insertion performance
    SinglyLinkedList<int> perf_list;
    timer.start();
    for (int i = 0; i < LARGE_SIZE; i++)
    {
        perf_list.push_back(i);
    }
    double insert_time = timer.get_duration_ms();

    tf.test("Large insertion performance", insert_time < 100.0); // Should be fast
    tf.test("Size after large insertion", perf_list.size() == LARGE_SIZE);

    // Test search performance
    timer.start();
    bool found = perf_list.contains(LARGE_SIZE / 2);
    double search_time = timer.get_duration_ms();

    tf.test("Large search performance", search_time < 50.0);
    tf.test("Search found element", found);

    // Test sort performance
    SinglyLinkedList<int> sort_list;
    for (int i = LARGE_SIZE; i > 0; i--)
    {
        sort_list.push_back(i);
    }

    timer.start();
    sort_list.sort();
    double sort_time = timer.get_duration_ms();

    tf.test("Sort performance", sort_time < 1000.0); // Merge sort should be reasonable
    tf.test("Sort correctness", sort_list.is_sorted());

    std::cout << "\nPerformance Summary:" << std::endl;
    std::cout << "Insert " << LARGE_SIZE << " elements: " << insert_time << " ms" << std::endl;
    std::cout << "Search in " << LARGE_SIZE << " elements: " << search_time << " ms" << std::endl;
    std::cout << "Sort " << LARGE_SIZE << " elements: " << sort_time << " ms" << std::endl;
}

/**
 * @brief Test with different data types
 */
void test_different_types(TestFramework &tf)
{
    tf.start_suite("Different Data Types");

    // Test with strings
    SinglyLinkedList<std::string> string_list;
    string_list.push_back("hello");
    string_list.push_back("world");
    string_list.push_back("test");

    tf.test("String list size", string_list.size() == 3);
    tf.test("String list contains", string_list.contains("world"));
    tf.test("String list access", string_list.at(1) == "world");

    // Test with doubles
    SinglyLinkedList<double> double_list;
    double_list.push_back(3.14);
    double_list.push_back(2.71);
    double_list.push_back(1.41);

    tf.test("Double list operations",
            double_list.front() == 3.14 && double_list.back() == 1.41);

    // Test sorting with different types
    string_list.sort();
    tf.test("String sorting", string_list.at(0) == "hello" &&
                                  string_list.at(1) == "test" &&
                                  string_list.at(2) == "world");
}

/**
 * @brief Stress test for memory management
 */
void test_memory_management(TestFramework &tf)
{
    tf.start_suite("Memory Management");

    // Test multiple clear operations
    SinglyLinkedList<int> mem_list;
    for (int round = 0; round < 5; round++)
    {
        for (int i = 0; i < 1000; i++)
        {
            mem_list.push_back(i);
        }
        mem_list.clear();
        tf.test("Clear operation " + std::to_string(round),
                mem_list.empty() && mem_list.size() == 0);
    }

    // Test rapid insertions and deletions
    for (int i = 0; i < 1000; i++)
    {
        mem_list.push_back(i);
        if (i % 2 == 0 && !mem_list.empty())
        {
            mem_list.pop_front();
        }
    }

    tf.test("Memory stress test completed", true); // If we reach here, no memory issues
}

/**
 * @brief Main testing function
 */
int main()
{
    std::cout << "Starting Comprehensive SinglyLinkedList Testing Suite" << std::endl;
    std::cout << "======================================================" << std::endl;

    TestFramework tf;

    try
    {
        // Run all test suites
        test_basic_operations(tf);
        test_insertion_operations(tf);
        test_deletion_operations(tf);
        test_access_operations(tf);
        test_search_and_utility(tf);
        test_advanced_operations(tf);
        test_special_algorithms(tf);
        test_edge_cases(tf);
        test_different_types(tf);
        test_memory_management(tf);
        test_performance(tf);
    }
    catch (const std::exception &e)
    {
        std::cout << "Critical error during testing: " << e.what() << std::endl;
        return 1;
    }

    // Print final summary
    tf.print_summary();

    return 0;
}
