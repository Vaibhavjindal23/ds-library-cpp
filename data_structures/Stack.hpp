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

#ifndef STACK_HPP
#define STACK_HPP

#include "array.hpp"       // Custom dynamic array implementation
#include <iostream>        // For printing
#include <stdexcept>       // For standard exception handling
#include <limits>
namespace data_structures {

/**
 * @brief A stack (LIFO) implementation using a dynamic Array<T> as the underlying container.
 * 
 * Provides standard stack operations: push, pop, top, size, etc.
 * Follows C++ template practices and includes basic error handling.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class Stack {
private:
    Array<T> arr;  ///< Internal container using custom dynamic array

public:
    // === Constructor ===

    /**
     * @brief Default constructor for Stack.
     */
    Stack();

    // === Basic Stack Operations ===

    /**
     * @brief Checks if the stack is empty.
     * 
     * @return true if stack has no elements.
     * @return false otherwise.
     */
    bool empty() const;

    /**
     * @brief Returns the number of elements in the stack.
     * 
     * @return int Size of the stack.
     */
    int size() const;

    /**
     * @brief Pushes an element onto the top of the stack.
     * 
     * @param value The element to push.
     */
    void push(const T& value);

    /**
     * @brief Removes the top element from the stack.
     * 
     * @throws std::underflow_error if the stack is empty.
     */
    void pop();

    /**
     * @brief Returns a reference to the top element.
     * 
     * @return Reference to top element.
     * @throws std::underflow_error if the stack is empty.
     */
    T& top();

    /**
     * @brief Returns a const reference to the top element.
     * 
     * @return Const reference to top element.
     * @throws std::underflow_error if the stack is empty.
     */
    const T& top() const;

    /**
     * @brief Removes all elements from the stack.
     */
    void clear();

    /**
     * @brief Prints the stack contents from top to bottom.
     */
    void print() const;

        /**
     * @brief Returns reference to element at a specific index from the top of the stack.
     * @param index_from_top Index from top (0 = top element)
     * @throws std::out_of_range if index is invalid.
     */
    T& at(int index_from_top);
    const T& at(int index_from_top) const;

    /**
     * @brief Returns reference to the bottom-most element of the stack.
     * @throws std::underflow_error if the stack is empty.
     */
    T& bottom();
    const T& bottom() const;

    /**
     * @brief Swaps the contents of this stack with another.
     * 
     * @param other Stack to swap with.
     */
    void swap(Stack<T>& other);

    /**
     * @brief Checks if two stacks are equal.
     * 
     * @param other Stack to compare.
     * @return true if both stacks have same elements in same order.
     */
    bool operator==(const Stack<T>& other) const;

    /**
     * @brief Converts the stack to a std::vector.
     * 
     * @return A vector containing the elements of the stack from top to bottom.
     */
    std::vector<T> to_vector() const;

    /**
     * @brief Reverses the order of elements in the stack.
     */
    void reverse();

};

// ====================== Function Definitions ====================== //

/**
 * @brief Default constructor: no need for manual initialization
 * since Array<T> handles its own construction.
 */
template <typename T>
Stack<T>::Stack() = default;

template <typename T>
bool Stack<T>::empty() const {
    return arr.size() == 0;
}

template <typename T>
int Stack<T>::size() const {
    return arr.size();
}

template <typename T>
void Stack<T>::push(const T& value) {
    arr.push_back(value);
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack underflow: cannot pop from an empty stack");
    }
    arr.pop_back();
}

template <typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw std::underflow_error("Stack underflow: stack is empty");
    }
    return arr[arr.size() - 1];
}

template <typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::underflow_error("Stack underflow: stack is empty");
    }
    return arr[arr.size() - 1];
}

template <typename T>
void Stack<T>::clear() {
    arr.clear();
}

template <typename T>
void Stack<T>::print() const {
    std::cout << "Stack (top to bottom): ";
    for (int i = arr.size() - 1; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
T& Stack<T>::at(int index_from_top) {
    if (index_from_top < 0 || index_from_top >= arr.size()) {
        throw std::out_of_range("Invalid index: out of stack bounds");
    }
    return arr[arr.size() - 1 - index_from_top];
}

template <typename T>
const T& Stack<T>::at(int index_from_top) const {
    if (index_from_top < 0 || index_from_top >= arr.size()) {
        throw std::out_of_range("Invalid index: out of stack bounds");
    }
    return arr[arr.size() - 1 - index_from_top];
}

template <typename T>
T& Stack<T>::bottom() {
    if (empty()) {
        throw std::underflow_error("Stack underflow: stack is empty");
    }
    return arr[0];
}

template <typename T>
const T& Stack<T>::bottom() const {
    if (empty()) {
        throw std::underflow_error("Stack underflow: stack is empty");
    }
    return arr[0];
}

template <typename T>
void Stack<T>::swap(Stack<T>& other) {
    using std::swap;
    swap(arr, other.arr);
}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& other) const {
    if (arr.size() != other.arr.size()) {
        return false;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
std::vector<T> Stack<T>::to_vector() const {
    std::vector<T> result;
    for (int i = arr.size() - 1; i >= 0; --i) {
        result.push_back(arr[i]);
    }
    return result;
}

template <typename T>
void Stack<T>::reverse() {
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i) {
        std::swap(arr[i], arr[n - i - 1]);
    }
}

}  // namespace data_structures

#endif  // STACK_HPP
