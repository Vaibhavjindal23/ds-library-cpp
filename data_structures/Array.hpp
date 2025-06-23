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

#ifndef ARRAY_HPP
#define ARRAY_HPP

// <iostream> is included to enable output streaming for the print() function.
// This allows us to display the array contents to standard output for debugging or logging.
#include<iostream>   
#include <vector> 
#include <algorithm>  // Needed for std::sort
// <stdexcept> is included to provide standard exception classes like std::out_of_range,
// which is used to signal errors such as invalid indexing in a clean, standard way.
#include<stdexcept>
#include <unordered_map>
#include <cmath>         // For std::sqrt
#include <limits>        // For std::numeric_limits

#include <unordered_set>  // For tracking unique elements efficiently 
#include <numeric>
#include <unordered_set>
namespace data_structures{

template<typename T>
class Array{
private :
    T* data;         // Pointer to the dynamically allocated array memory.
    int capacity;    // Current allocated capacity (total slots).
    int length;      // Number of elements currently stored.

    /**
     * @brief Resize the internal array to double its current capacity.
     * 
     * Called internally when the array is full and needs more space.
     * This method copies existing elements to the new larger array.
     */
    void resize();

public:
    // Constructor: initializes the array with an initial capacity of 4.
    Array();
    
    
    // Destructor: releases allocated memory to prevent leaks.
    ~Array();

    /**
     * @brief Adds an element at the end of the array.
     * 
     * @param value The element to add.
     */
    void push_back(const T& value);
    
    /**
     * @brief Removes the last element from the array.
     * If the array is empty, does nothing.
     */
    void pop_back();
    
    /**
     * @brief Access element at a specific index with bounds checking.
     * 
     * Throws std::out_of_range if the index is invalid.
     * 
     * @param index Index of the element (0-based).
     * @return Reference to the element at index.
     */
    T& operator[](int index);

    /**
     * @brief Access element at a specific index (const version).
     * 
     * Throws std::out_of_range if the index is invalid.
     * 
     * @param index Index of the element (0-based).
     * @return Const reference to the element at index.
     */
    const T& operator[](int index) const;

    /**
     * @brief Inserts an element at the specified index, shifting elements to the right.
     * 
     * Throws std::out_of_range if index is invalid (not between 0 and length).
     * 
     * @param index Position to insert element.
     * @param value Element to insert.
     */
    void insert(int index, const T& value);
    
    /**
     * @brief Removes the element at the specified index, shifting elements to the left.
     * 
     * Throws std::out_of_range if index is invalid.
     * 
     * @param index Position of the element to remove.
     */
    void remove(int index);

    /**
     * @brief Clears the array (sets length to zero).
     * Does not reduce capacity.
     */
    void clear();

    /**
     * @brief Returns the number of elements currently stored.
     * 
     * @return Current size.
     */
    int size() const;

    /**
     * @brief Returns the total capacity of the allocated array.
     * 
     * @return Capacity.
     */
    int get_capacity() const;

    /**
     * @brief Prints the contents of the array to standard output.
     */
    void print() const;

    // Delete copy constructor and assignment operator to prevent shallow copies.
    // Array(const Array&) = delete;
    // Array& operator=(const Array&) = delete;

    /**
    * @brief Reverses the contents of the array in-place.
    */
    void reverse();

    /**
    * @brief Checks if the array contents form a palindrome.
    * 
    * @return true if array is a palindrome, false otherwise.
    */
    bool is_palindrome() const;
    
    /**
     * @brief Finds the index of the first occurrence of a value.
     * 
     * @param value The element to search for.
     * @return Index of the element if found, otherwise -1.
     */
    int find(const T& value) const;
    
    /**
     * @brief Rotates the array to the left by k positions using reverse algorithm.
     * 
     * @param k Number of positions to rotate left.
     */
    void rotate_left(int k);

    /**
     * @brief Rotates the array to the right by k positions using reverse algorithm.
     * 
     * @param k Number of positions to rotate right.
     */
    void rotate_right(int k);
    
    /**
     * @brief Returns the sum of all elements in the array.
     * 
     * @return Sum of elements.
     */
    T sum() const;

    /**
     * @brief Returns the average (mean) of all elements in the array.
     * 
     * @return Average value.
     */
    double average() const;

    /**
     * @brief Returns the median of the array.
     * 
     * If the array has even length, returns average of middle two.
     * Throws if array is empty.
     * 
     * @return Median value.
     */
    double median() const;
    
        /**
     * @brief Sorts the array elements in ascending order.
     */
    void sort();
    
    /**
     * @brief Checks if the array is sorted in ascending order.
     * @return true if sorted, false otherwise.
     */
    bool is_sorted() const;

    /**
     * @brief Finds and returns the minimum element in the array.
     * Throws std::runtime_error if the array is empty.
     * @return Minimum element of type T.
     */
    T min() const;

    /**
     * @brief Finds and returns the maximum element in the array.
     * Throws std::runtime_error if the array is empty.
     * @return Maximum element of type T.
     */
    T max() const;
    
        /**
     * @brief Counts the occurrences of a given value in the array.
     * 
     * @param value The element to count.
     * @return int Number of times the value appears.
     */
    int count(const T& value) const;

    /**
     * @brief Swaps the elements at two given indices.
     * 
     * @param i Index of the first element.
     * @param j Index of the second element.
     * 
     * @throws std::out_of_range if either index is invalid.
     */
    void swap(int i, int j);

    /**
     * @brief Returns a new Array containing only unique elements from the current array.
     * 
     * @return Array<T> New array with duplicates removed.
     */
    Array<T> find_unique() const;
    
        /**
     * @brief Checks if the array contains the specified element.
     * 
     * @param value Element to check.
     * @return true if element is found, false otherwise.
     */
    bool contains(const T& value) const;

    /**
     * @brief Removes duplicate elements from the array in-place.
     */
    void remove_duplicates();
    
    /**
     * @brief Returns the majority element (appearing more than n/2 times) if exists.
     * Throws std::runtime_error if no majority element is found.
     * 
     * @return T Majority element.
     */
    T majority_element() const;

    /**
     * @brief Sets all elements of the array to zero.
     * Requires T to support assignment from int 0.
     */
    void set_all_zero();
    
    /**
     * @brief Returns the index of the first element >= value (lower bound).
     * Requires the array to be sorted.
     * 
     * @param value The value to search.
     * @return Index of the lower bound, or -1 if not found.
     */
    int lower_bound(const T& value) const;

    /**
     * @brief Returns the index of the first element > value (upper bound).
     * Requires the array to be sorted.
     * 
     * @param value The value to search.
     * @return Index of the upper bound, or -1 if not found.
     */
    int upper_bound(const T& value) const;

    /**
     * @brief Returns the floor (greatest element <= value).
     * Requires the array to be sorted.
     * 
     * @param value The value to search.
     * @return Floor element.
     */
    T floor_element(const T& value) const;

    /**
     * @brief Returns the ceiling (smallest element >= value).
     * Requires the array to be sorted.
     * 
     * @param value The value to search.
     * @return Ceiling element.
     */
    T ceil_element(const T& value) const;
    
    /**
     * @brief Returns the most frequent element (mode) in the array.
     * 
     * @return The element with the highest frequency.
     * Throws if the array is empty.
     */
    T mode() const;

    /**
     * @brief Returns a new Array<T> of prefix sums.
     * Assumes T supports addition and copy.
     * 
     * @return Array<T> containing prefix sums.
     */
    Array<T> prefix_sum_array() const;

    /**
     * @brief Returns the range of array (max - min).
     * 
     * @return Range of values.
     */
    T range() const;

    /**
     * @brief Checks if the array forms an arithmetic progression.
     * 
     * @return true if array is arithmetic sequence.
     */
    bool is_arithmetic_progression() const;

    /**
     * @brief Checks if the array forms a geometric progression.
     * 
     * @return true if array is geometric sequence.
     */
    bool is_geometric_progression() const;

    /**
     * @brief Returns the standard deviation of the array.
     * 
     * @return Standard deviation as double.
     */
    double standard_deviation() const;

    /**
     * @brief Sets all elements of the array to a specified value.
     * 
     * @param value The value to assign to each element.
     */
    void fill(const T& value);

    /**
     * @brief Computes the cumulative product of the array elements.
     * @return A new Array<T> where each element is the cumulative product.
     */
    Array<T> cumulative_product() const;

    /**
     * @brief Checks if any subarray sums up to the given target value.
     * @param target The sum to search for.
     * @return true if such a subarray exists, false otherwise.
     */
    bool subarray_sum_equals(const T& target) const;

    /**
     * @brief Returns the kth smallest element (1-based).
     * @param k Position of the smallest element to find.
     * @return The kth smallest value.
     */
    T kth_smallest(int k) const;

    /**
     * @brief Returns the kth largest element (1-based).
     * @param k Position of the largest element to find.
     * @return The kth largest value.
     */
    T kth_largest(int k) const;

    /**
     * @brief Computes the GCD (greatest common divisor) of all array elements.
     * @return GCD of array elements.
     */
    T gcd() const;

    /**
     * @brief Computes the LCM (least common multiple) of all array elements.
     * @return LCM of array elements.
     */
    T lcm() const;

    /**
     * @brief Merges two sorted arrays into a new sorted array.
     * @param other Another sorted array.
     * @return A merged sorted array.
     */
    Array<T> merge_sorted(const Array<T>& other) const;

    /**
     * @brief Rearranges the array in zigzag fashion: a < b > c < d > e ...
     */
    void zigzag();

    /**
     * @brief Finds the missing number in an array containing numbers from 1 to n with exactly one number missing.
     * 
     * Throws runtime_error if the array size is not equal to n-1.
     * @return The missing number.
     */
    T find_missing_number() const;
    
};



   
template <typename T>
Array<T>::Array()
    : capacity(4), length(0), data(new T[4]) {
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template<typename T>
void Array<T>::resize(){
    capacity = capacity * 2;
    T* new_data = new T[capacity];
    for(int i =0; i<length; i++){
         new_data[i] = data[i];
    } 
    delete[] data;
    data = new_data;
}

template<typename T>
void Array<T>::push_back(const T&value){
    if(length == capacity) resize();
    data[length++] = value;
}

template <typename T>
void Array<T>::pop_back() {
    if (length > 0) {
        --length;
    }
}

template<typename T>
T& Array<T>::operator[](int index){
    if(index < 0 || index>=length){
        throw std:: out_of_range("Array index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Array index out of bounds");
    }
    return data[index];
}

template <typename T>
void Array<T>::insert(int index, const T& value) {
    if (index < 0 || index > length) {
        throw std::out_of_range("Insert index out of bounds");
    }
    if (length == capacity) {
        resize();
    }
    // Shift elements right from index
    for (int i = length; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++length;
}

template <typename T>
void Array<T>::remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Remove index out of bounds");
    }
    // Shift elements left to overwrite element at index
    for (int i = index; i < length - 1; ++i) {
        data[i] = data[i + 1];
    }
    --length;
}

template <typename T>
void Array<T>::clear() {
    length = 0;  // Simply reset length; capacity remains same
}

template <typename T>
int Array<T>::size() const {
    return length;
}

template <typename T>
int Array<T>::get_capacity() const {
    return capacity;
}

template <typename T>
void Array<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < length; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "]\n";
}

template <typename T>
void Array<T>::reverse() {
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        std::swap(data[i], data[j]);
    }
}

template <typename T>
bool Array<T>::is_palindrome() const {
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        if (data[i] != data[j]) {
            return false;
        }
    }
    return true;
}

template <typename T>
int Array<T>::find(const T& value) const {
    for (int i = 0; i < length; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Array<T>::rotate_left(int k) {
    if (length == 0) return;
    k %= length;  // Normalize if k > length
    if (k == 0) return;

    // Reverse first k elements
    std::reverse(data, data + k);
    // Reverse remaining elements
    std::reverse(data + k, data + length);
    // Reverse whole array
    std::reverse(data, data + length);
}

template <typename T>
void Array<T>::rotate_right(int k) {
    if (length == 0) return;
    k %= length;
    if (k == 0) return;

    // Right rotation by k is left rotation by (length - k)
    rotate_left(length - k);
}

template <typename T>
T Array<T>::sum() const {
    T total = 0;
    for (int i = 0; i < length; ++i) {
        total += data[i];
    }
    return total;
}

template <typename T>
double Array<T>::average() const {
    if (length == 0) return 0.0;
    return static_cast<double>(sum()) / length;
}

template <typename T>
double Array<T>::median() const {
    if (length == 0) {
        throw std::runtime_error("Cannot compute median of empty array");
    }

    // Make a temporary copy to avoid modifying the original array
    T* temp = new T[length];
    for (int i = 0; i < length; ++i) {
        temp[i] = data[i];
    }

    std::sort(temp, temp + length);  // Sort the copy

    double med;
    if (length % 2 == 1) {
        med = temp[length / 2];  // Middle element
    } else {
        med = (temp[length / 2 - 1] + temp[length / 2]) / 2.0;
    }

    delete[] temp;
    return med;
}

template <typename T>
void Array<T>::sort() {
    std::sort(data, data + length);
}

template <typename T>
bool Array<T>::is_sorted() const {
    for (int i = 1; i < length; ++i) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
T Array<T>::min() const {
    if (length == 0) {
        throw std::runtime_error("Array is empty - no minimum element.");
    }
    return *std::min_element(data, data + length);
}

template <typename T>
T Array<T>::max() const {
    if (length == 0) {
        throw std::runtime_error("Array is empty - no maximum element.");
    }
    return *std::max_element(data, data + length);
}

template <typename T>
int Array<T>::count(const T& value) const {
    int cnt = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] == value) {
            ++cnt;
        }
    }
    return cnt;
}

template <typename T>
void Array<T>::swap(int i, int j) {
    if (i < 0 || i >= length || j < 0 || j >= length) {
        throw std::out_of_range("Swap indices out of bounds");
    }
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template <typename T>
Array<T> Array<T>::find_unique() const {
    Array<T> unique_array;
    std::unordered_set<T> seen;

    for (int i = 0; i < length; ++i) {
        if (seen.find(data[i]) == seen.end()) {
            unique_array.push_back(data[i]);
            seen.insert(data[i]);
        }
    }

    return unique_array;
}

template <typename T>
bool Array<T>::contains(const T& value) const {
    for (int i = 0; i < length; ++i) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
void Array<T>::remove_duplicates() {
    std::unordered_set<T> seen;
    int new_length = 0;

    for (int i = 0; i < length; ++i) {
        if (seen.find(data[i]) == seen.end()) {
            data[new_length++] = data[i];
            seen.insert(data[i]);
        }
    }

    length = new_length;
}

template <typename T>
T Array<T>::majority_element() const {
    int count = 0;
    T candidate;

    // Boyer-Moore majority voting
    for (int i = 0; i < length; ++i) {
        if (count == 0) {
            candidate = data[i];
            count = 1;
        } else if (data[i] == candidate) {
            ++count;
        } else {
            --count;
        }
    }

    // Verify candidate is majority
    count = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] == candidate) {
            ++count;
        }
    }
    if (count > length / 2) {
        return candidate;
    }
    throw std::runtime_error("No majority element found");
}

template <typename T>
void Array<T>::set_all_zero() {
    for (int i = 0; i < length; ++i) {
        data[i] = 0;  // Requires T supports 0 assignment
    }
}

template <typename T>
int Array<T>::lower_bound(const T& value) const {
    if (!is_sorted()) {
        throw std::logic_error("Array must be sorted to use lower_bound.");
    }

    int left = 0, right = length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (data[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return (left < length) ? left : -1;
}

template <typename T>
int Array<T>::upper_bound(const T& value) const {
    if (!is_sorted()) {
        throw std::logic_error("Array must be sorted to use upper_bound.");
    }

    int left = 0, right = length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (data[mid] <= value)
            left = mid + 1;
        else
            right = mid;
    }

    return (left < length) ? left : -1;
}

template <typename T>
T Array<T>::floor_element(const T& value) const {
    if (!is_sorted()) {
        throw std::logic_error("Array must be sorted to find floor.");
    }

    T result;
    bool found = false;

    for (int i = 0; i < length; ++i) {
        if (data[i] <= value) {
            result = data[i];
            found = true;
        } else {
            break;
        }
    }

    if (!found) {
        throw std::runtime_error("No floor element found.");
    }

    return result;
}

template <typename T>
T Array<T>::ceil_element(const T& value) const {
    if (!is_sorted()) {
        throw std::logic_error("Array must be sorted to find ceil.");
    }

    for (int i = 0; i < length; ++i) {
        if (data[i] >= value) {
            return data[i];
        }
    }

    throw std::runtime_error("No ceiling element found.");
}

template <typename T>
T Array<T>::mode() const {
    if (length == 0) {
        throw std::runtime_error("Array is empty");
    }
    std::unordered_map<T, int> freq;
    T result = data[0];
    int max_count = 0;

    for (int i = 0; i < length; ++i) {
        ++freq[data[i]];
        if (freq[data[i]] > max_count) {
            max_count = freq[data[i]];
            result = data[i];
        }
    }
    return result;
}

template <typename T>
Array<T> Array<T>::prefix_sum_array() const {
    Array<T> result; 
    if (length == 0) return result;

    T sum = data[0];
    result.push_back(sum);
    for (int i = 1; i < length; ++i) {
        sum = sum + data[i];
        result.push_back(sum);
    }
    return result;
}

template <typename T>
T Array<T>::range() const {
    if (length == 0) throw std::runtime_error("Array is empty");

    T min_val = data[0], max_val = data[0];
    for (int i = 1; i < length; ++i) {
        if (data[i] < min_val) min_val = data[i];
        if (data[i] > max_val) max_val = data[i];
    }
    return max_val - min_val;
}

template <typename T>
bool Array<T>::is_arithmetic_progression() const {
    if (length < 2) return true;

    T diff = data[1] - data[0];
    for (int i = 2; i < length; ++i) {
        if (data[i] - data[i - 1] != diff) return false;
    }
    return true;
}

template <typename T>
bool Array<T>::is_geometric_progression() const {
    if (length < 2) return true;
    if (data[0] == 0) return false;

    T ratio = data[1] / data[0];
    for (int i = 2; i < length; ++i) {
        if (data[i - 1] == 0 || data[i] / data[i - 1] != ratio) return false;
    }
    return true;
}

template <typename T>
double Array<T>::standard_deviation() const {
    if (length == 0) return 0.0;

    double mean = 0;
    for (int i = 0; i < length; ++i) {
        mean += static_cast<double>(data[i]);
    }
    mean /= length;

    double variance = 0;
    for (int i = 0; i < length; ++i) {
        double diff = static_cast<double>(data[i]) - mean;
        variance += diff * diff;
    }
    variance /= length;

    return std::sqrt(variance);
}

template <typename T>
void Array<T>::fill(const T& value) {
    for (int i = 0; i < length; ++i) {
        data[i] = value;
    }
}


template <typename T>
Array<T> Array<T>::cumulative_product() const {
    Array<T> result;
    if (length == 0) return result;

    T prod = data[0];
    result.push_back(prod);
    for (int i = 1; i < length; ++i) {
        prod *= data[i];
        result.push_back(prod);
    }
    return result;
}

template <typename T>
bool Array<T>::subarray_sum_equals(const T& target) const {
    std::unordered_set<T> prefix_sums;
    T sum = 0;
    prefix_sums.insert(0);
    for (int i = 0; i < length; ++i) {
        sum += data[i];
        if (prefix_sums.count(sum - target)) return true;
        prefix_sums.insert(sum);
    }
    return false;
}

template <typename T>
T Array<T>::kth_smallest(int k) const {
    if (k <= 0 || k > length) throw std::out_of_range("Invalid k");
    std::vector<T> temp(data, data + length);
    std::nth_element(temp.begin(), temp.begin() + k - 1, temp.end());
    return temp[k - 1];
}

template <typename T>
T Array<T>::kth_largest(int k) const {
    if (k <= 0 || k > length) throw std::out_of_range("Invalid k");
    std::vector<T> temp(data, data + length);
    std::nth_element(temp.begin(), temp.end() - k, temp.end());
    return temp[length - k];
}

template <typename T>
T gcd_helper(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

template <typename T>
T Array<T>::gcd() const {
    if (length == 0) throw std::runtime_error("Empty array");
    T result = data[0];
    for (int i = 1; i < length; ++i) {
        result = gcd_helper(result, data[i]);
    }
    return result;
}

template <typename T>
T lcm_helper(T a, T b) {
    return (a / gcd_helper(a, b)) * b;
}

template <typename T>
T Array<T>::lcm() const {
    if (length == 0) throw std::runtime_error("Empty array");
    T result = data[0];
    for (int i = 1; i < length; ++i) {
        result = lcm_helper(result, data[i]);
    }
    return result;
}

template <typename T>
Array<T> Array<T>::merge_sorted(const Array<T>& other) const {
    Array<T> result;
    int i = 0, j = 0;
    while (i < length && j < other.length) {
        if (data[i] <= other.data[j]) {
            result.push_back(data[i++]);
        } else {
            result.push_back(other.data[j++]);
        }
    }
    while (i < length) result.push_back(data[i++]);
    while (j < other.length) result.push_back(other.data[j++]);
    return result;
}

template <typename T>
void Array<T>::zigzag() {
    for (int i = 0; i < length - 1; ++i) {
        if (i % 2 == 0) {
            if (data[i] > data[i + 1]) {
                // Swap data[i] and data[i + 1]
                T temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        } else {
            if (data[i] < data[i + 1]) {
                // Swap data[i] and data[i + 1]
                T temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
    }
}

template <typename T>
T Array<T>::find_missing_number() const {
    int n = length + 1; // Because one number missing in 1..n
    if (length != n - 1) {
        throw std::runtime_error("Array size mismatch for find_missing_number");
    }
    // Use formula for sum 1..n = n*(n+1)/2
    T expected_sum = static_cast<T>(n) * static_cast<T>(n + 1) / 2;
    T actual_sum = 0;
    for (int i = 0; i < length; ++i) {
        actual_sum += data[i];
    }
    return expected_sum - actual_sum;
}
} //namespace data_structures
#endif
 
