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

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>

namespace data_structures {

/**
 * @brief A dynamically resizing generic queue implemented using a circular buffer.
 * 
 * Supports basic queue operations with amortized O(1) complexity.
 * 
 * @tparam T Type of elements stored in the queue.
 */
template <typename T>
class Queue {
private:
    T* data;           // Pointer to dynamically allocated array
    int capacity;      // Total allocated capacity
    int front_index;   // Index of the front element
    int rear_index;    // Index of the next free slot for insertion
    int length;        // Number of elements currently stored

    /**
     * @brief Resizes the internal buffer to double the current capacity.
     * Copies elements in correct order to the new buffer.
     */
    void resize();

public:
    // Constructor: initializes an empty queue with initial capacity of 4
    Queue();

    // Destructor: releases allocated memory
    ~Queue();

    // Disable copy constructor and assignment operator to prevent shallow copies
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    /**
     * @brief Adds an element to the rear of the queue.
     * @param value The element to enqueue.
     */
    void enqueue(const T& value);

    /**
     * @brief Removes the front element from the queue.
     * @throws std::out_of_range if queue is empty.
     */
    void dequeue();

    /**
     * @brief Returns a reference to the front element.
     * @throws std::out_of_range if queue is empty.
     * @return Reference to the front element.
     */
    T& front();

    /**
     * @brief Returns a const reference to the front element.
     * @throws std::out_of_range if queue is empty.
     * @return Const reference to the front element.
     */
    const T& front() const;

    /**
     * @brief Returns a reference to the rear element (the last enqueued element).
     * @throws std::out_of_range if queue is empty.
     * @return Reference to the rear element.
     */
    T& back();

    /**
     * @brief Returns a const reference to the rear element.
     * @throws std::out_of_range if queue is empty.
     * @return Const reference to the rear element.
     */
    const T& back() const;

    /**
     * @brief Returns true if the queue is empty.
     */
    bool empty() const;

    /**
     * @brief Returns the number of elements in the queue.
     */
    int size() const;

    /**
     * @brief Clears the queue, removing all elements.
     * Capacity remains unchanged.
     */
    void clear();

    /**
     * @brief Prints the elements of the queue from front to rear.
     */
    void print() const;
};

// Definitions

template <typename T>
Queue<T>::Queue()
    : capacity(4), front_index(0), rear_index(0), length(0), data(new T[capacity]) {}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
void Queue<T>::resize() {
    int new_capacity = capacity * 2;
    if (new_capacity <= 0 || new_capacity > 100000000) {
        throw std::length_error("Queue capacity overflow or invalid size");
    }

    std::cout << "Resizing from " << capacity << " to " << new_capacity << std::endl;

    T* new_data = new T[new_capacity];

    for (int i = 0; i < length; i++) {
        new_data[i] = data[(front_index + i) % capacity];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
    front_index = 0;
    rear_index = length;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    if (length == capacity) {
        resize();
    }
    data[rear_index] = value;
    rear_index = (rear_index + 1) % capacity;
    length++;
}

template <typename T>
void Queue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Queue is empty. Cannot dequeue.");
    }
    front_index = (front_index + 1) % capacity;
    length--;
}

template <typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw std::out_of_range("Queue is empty. No front element.");
    }
    return data[front_index];
}

template <typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty. No front element.");
    }
    return data[front_index];
}

template <typename T>
T& Queue<T>::back() {
    if (empty()) {
        throw std::out_of_range("Queue is empty. No back element.");
    }
    // rear_index points to next insertion spot, so last element is rear_index - 1 mod capacity
    int back_pos = (rear_index - 1 + capacity) % capacity;
    return data[back_pos];
}

template <typename T>
const T& Queue<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty. No back element.");
    }
    int back_pos = (rear_index - 1 + capacity) % capacity;
    return data[back_pos];
}

template <typename T>
bool Queue<T>::empty() const {
    return length == 0;
}

template <typename T>
int Queue<T>::size() const {
    return length;
}

template <typename T>
void Queue<T>::clear() {
    front_index = 0;
    rear_index = 0;
    length = 0;
}

template <typename T>
void Queue<T>::print() const {
    std::cout << "Queue contents: ";
    for (int i = 0; i < length; i++) {
        std::cout << data[(front_index + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

} // namespace data_structures

#endif // QUEUE_HPP
