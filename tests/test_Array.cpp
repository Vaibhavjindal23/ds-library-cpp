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
#include <stdexcept>
#include "../data_structures/Array.hpp"

using namespace std;
using namespace data_structures;

void test_push_pop() {
    cout << "\n=== test_push_pop ===\n";
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.print();

    arr.pop_back();
    arr.print();

    arr.pop_back();
    arr.pop_back();
    arr.pop_back();  // popping empty array - should handle gracefully or do nothing

    arr.print();
}

void test_access_and_insert_remove() {
    cout << "\n=== test_access_and_insert_remove ===\n";
    Array<int> arr;
    for (int i = 1; i <= 5; ++i) arr.push_back(i * 10);

    try {
        cout << "Element at index 2: " << arr[2] << "\n"; // Should print 30
        arr[2] = 35;
        cout << "After modification: ";
        arr.print();

        arr.insert(2, 25);
        cout << "After insert at index 2: ";
        arr.print();

        arr.remove(4);
        cout << "After remove at index 4: ";
        arr.print();

        // Try invalid index
        arr.insert(100, 50);
    } catch (const out_of_range& e) {
        cout << "Caught exception on invalid insert: " << e.what() << "\n";
    }

    try {
        cout << arr[100] << "\n";
    } catch (const out_of_range& e) {
        cout << "Caught exception on invalid access: " << e.what() << "\n";
    }
}

void test_reverse_and_palindrome() {
    cout << "\n=== test_reverse_and_palindrome ===\n";
    Array<int> arr;
    for (int v : {1, 2, 3, 2, 1}) arr.push_back(v);

    cout << "Is palindrome? " << boolalpha << arr.is_palindrome() << "\n";

    arr.reverse();
    cout << "Reversed array: ";
    arr.print();
}

void test_statistics() {
    cout << "\n=== test_statistics ===\n";
    Array<double> arr;
    for (double v : {10.5, 20.5, 30.0, 40.0, 50.0}) arr.push_back(v);

    cout << "Sum: " << arr.sum() << "\n";
    cout << "Average: " << arr.average() << "\n";
    cout << "Median: " << arr.median() << "\n";
    cout << "Standard Deviation: " << arr.standard_deviation() << "\n";
    cout << "Range: " << arr.range() << "\n";
}

void test_search_and_sort() {
    cout << "\n=== test_search_and_sort ===\n";
    Array<int> arr;
    for (int v : {5, 3, 8, 1, 9, 7}) arr.push_back(v);

    cout << "Is sorted? " << boolalpha << arr.is_sorted() << "\n";
    arr.sort();
    cout << "After sorting: ";
    arr.print();

    cout << "Is sorted now? " << boolalpha << arr.is_sorted() << "\n";

    cout << "Find 8 at index: " << arr.find(8) << "\n";
    cout << "Count 3 occurrences: " << arr.count(3) << "\n";

    cout << "Lower bound of 6: " << arr.lower_bound(6) << "\n";
    cout << "Upper bound of 6: " << arr.upper_bound(6) << "\n";
    cout << "Floor of 6: " << arr.floor_element(6) << "\n";
    cout << "Ceiling of 6: " << arr.ceil_element(6) << "\n";
}

void test_unique_and_duplicates() {
    cout << "\n=== test_unique_and_duplicates ===\n";
    Array<int> arr;
    for (int v : {1, 2, 2, 3, 4, 4, 4, 5}) arr.push_back(v);

    cout << "Original array: ";
    arr.print();

    auto unique_arr = arr.find_unique();
    cout << "Unique elements: ";
    unique_arr.print();

    arr.remove_duplicates();
    cout << "After removing duplicates in-place: ";
    arr.print();
}

void test_majority_element() {
    cout << "\n=== test_majority_element ===\n";
    Array<int> arr;
    for (int v : {1, 2, 3, 2, 2, 2, 5}) arr.push_back(v);

    try {
        int maj = arr.majority_element();
        cout << "Majority element: " << maj << "\n";
    } catch (const runtime_error& e) {
        cout << "No majority element found: " << e.what() << "\n";
    }
}

void test_math_operations() {
    cout << "\n=== test_math_operations ===\n";
    Array<int> arr;
    for (int v : {2, 3, 4, 5}) arr.push_back(v);

    cout << "Prefix sums: ";
    arr.prefix_sum_array().print();

    cout << "Cumulative product: ";
    arr.cumulative_product().print();

    cout << "GCD: " << arr.gcd() << "\n";
    cout << "LCM: " << arr.lcm() << "\n";

    cout << "3rd smallest: " << arr.kth_smallest(3) << "\n";
    cout << "2nd largest: " << arr.kth_largest(2) << "\n";
}

void test_merge_and_zigzag() {
    cout << "\n=== test_merge_and_zigzag ===\n";
    Array<int> arr1, arr2;

    for (int v : {1, 3, 5, 7}) arr1.push_back(v);
    for (int v : {2, 4, 6, 8}) arr2.push_back(v);

    auto merged = arr1.merge_sorted(arr2);
    cout << "Merged array: ";
    merged.print();

    Array<int> zigzag_arr;
    for (int v : {4, 3, 7, 8, 6, 2, 1}) zigzag_arr.push_back(v);
    zigzag_arr.zigzag();
    cout << "Zigzag rearranged array: ";
    zigzag_arr.print();
}

void test_find_missing_number() {
    cout << "\n=== test_find_missing_number ===\n";
    Array<int> arr;
    for (int v : {1, 2, 4, 5, 6}) arr.push_back(v); // missing 3

    try {
        int missing = arr.find_missing_number();
        cout << "Missing number: " << missing << "\n";
    } catch (const runtime_error& e) {
        cout << "Error finding missing number: " << e.what() << "\n";
    }
}

int main() {
    cout << "Testing Array<T> class functions...\n";

    test_push_pop();
    test_access_and_insert_remove();
    test_reverse_and_palindrome();
    test_statistics();
    test_search_and_sort();
    test_unique_and_duplicates();
    test_majority_element();
    test_math_operations();
    test_merge_and_zigzag();
    test_find_missing_number();

    cout << "\nAll tests completed.\n";
    return 0;
}
