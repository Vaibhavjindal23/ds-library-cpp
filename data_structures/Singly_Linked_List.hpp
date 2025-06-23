#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

namespace data_structures {

/**
 * @brief A generic singly linked list implementation.
 * 
 * Supports dynamic insertions, deletions, traversal, and search operations.
 * Manages memory safely and efficiently.
 * 
 * @tparam T The type of elements stored in the list.
 */
template <typename T>
class SinglyLinkedList {
private:
    /**
     * @brief Node structure representing each element in the list.
     */
    struct Node {
        T data;         ///< Data stored in the node
        Node* next;     ///< Pointer to the next node

        /**
         * @brief Construct a new Node.
         * 
         * @param data The value to store.
         * @param next Pointer to the next node (default is nullptr).
         */
        Node(const T& data, Node* next = nullptr);
    };

    Node* head;          ///< Pointer to the first node in the list
    int list_size;       ///< Tracks the number of elements in the list

    // Helper functions for sorting
    Node* merge_sorted_lists(Node* l1, Node* l2);
    Node* merge_sort(Node* head);

public:
    // === Constructors & Destructor ===

    /**
     * @brief Construct an empty singly linked list.
     */
    SinglyLinkedList();

    /**
     * @brief Destroys the list and deallocates all nodes.
     */
    ~SinglyLinkedList();

    // === Basic Operations ===

    /**
     * @brief Checks whether the list is empty.
     * 
     * @return true if the list has no elements, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Returns the number of elements in the list.
     * 
     * @return int The number of elements.
     */
    int size() const;

    /**
     * @brief Inserts an element at the beginning of the list.
     * 
     * @param value The value to insert.
     */
    void push_front(const T& value);

    /**
     * @brief Inserts an element at the end of the list.
     * 
     * @param value The value to insert.
     */
    void push_back(const T& value);

    /**
     * @brief Inserts an element at a specified index.
     * 
     * @param index The position where the value should be inserted.
     * @param value The value to insert.
     * 
     * @throws std::out_of_range If the index is invalid.
     */
    void insert(int index, const T& value);

    /**
     * @brief Removes the first element of the list.
     * 
     * @throws std::underflow_error If the list is empty.
     */
    void pop_front();

    /**
     * @brief Removes the last element of the list.
     * 
     * @throws std::underflow_error If the list is empty.
     */
    void pop_back();

    /**
     * @brief Removes an element at a given index.
     * 
     * @param index The index of the element to remove.
     * 
     * @throws std::out_of_range If the index is invalid.
     */
    void remove(int index);

    /**
     * @brief Accesses the first element of the list.
     * 
     * @return T& Reference to the first element.
     * 
     * @throws std::underflow_error If the list is empty.
     */
    T& front();

    /**
     * @brief Accesses the last element of the list.
     * 
     * @return T& Reference to the last element.
     * 
     * @throws std::underflow_error If the list is empty.
     */
    T& back();

    /**
     * @brief Accesses the element at a specified index.
     * 
     * @param index The index of the element.
     * 
     * @return T& Reference to the element at the index.
     * 
     * @throws std::out_of_range If the index is invalid.
     */
    T& at(int index);

    /**
     * @brief Const version of at() to access an element.
     * 
     * @param index The index of the element.
     * 
     * @return const T& Const reference to the element at the index.
     * 
     * @throws std::out_of_range If the index is invalid.
     */
    const T& at(int index) const;

    /**
     * @brief Removes all elements from the list.
     */
    void clear();

    /**
     * @brief Prints the list contents from front to back.
     */
    void print() const;

    /**
     * @brief Checks if the list contains a given value.
     * 
     * @param value The value to search for.
     * @return true If the value exists in the list.
     * @return false Otherwise.
     */
    bool contains(const T& value) const;

    /**
     * @brief Reverses the list in place.
     */
    void reverse();

    /**
     * @brief Deleted copy constructor to avoid accidental copies.
     */
    // SinglyLinkedList(const SinglyLinkedList&) = delete;
       SinglyLinkedList(const SinglyLinkedList&);
    /**
     * @brief Deleted copy assignment to avoid accidental copies.
     */
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    /**
     * @brief Removes the first node containing the specified value.
     * 
     * @param value The value to remove.
     * @return true if an element was removed, false if not found.
     */
    bool remove_value(const T& value);

    /**
     * @brief Finds the index of the first occurrence of the given value.
     * 
     * @param value The value to search for.
     * @return int The index of the value, or -1 if not found.
     */
    int find(const T& value) const;

    /**
     * @brief Appends another list to the end of this list.
     * 
     * @param other The list to append.
     */
    void append(const SinglyLinkedList<T>& other);

    /**
     * @brief Inserts an element maintaining ascending sorted order.
     * 
     * @param value The value to insert.
     */
    void insert_sorted(const T& value);

    /**
     * @brief Checks if the list is sorted in ascending order.
     * 
     * @return true if sorted, false otherwise.
     */
    bool is_sorted() const;

    /**
     * @brief Returns a sublist from index `start` (inclusive) to `end` (exclusive).
     * 
     * @param start Starting index (inclusive).
     * @param end Ending index (exclusive).
     * @return A new SinglyLinkedList<T> containing the sliced portion.
     * 
     * @throws std::out_of_range if indices are invalid.
     */
    SinglyLinkedList<T> slice(int start, int end) const;

    /**
     * @brief Removes all duplicate elements, preserving first occurrences.
     */
    void unique();

    /**
     * @brief Sorts the list in ascending order using merge sort.
     */
    void sort();

    /**
     * @brief Merges another sorted list into this one (also sorted).
     * 
     * @param other The other sorted list.
     */
    void merge(const SinglyLinkedList<T>& other);

    /**
     * @brief Rotates the list to the left by k positions.
     * 
     * @param k Number of positions to rotate.
     */
    void rotate_left(int k);

    /**
     * @brief Rotates the list to the right by k positions.
     * 
     * @param k Number of positions to rotate.
     */
    void rotate_right(int k);

     /**
     * @brief Returns reference to the middle element.
     * @return T& Middle node's data.
     * @throw std::runtime_error if list is empty.
     */
    T& middle();

    /**
     * @brief Returns reference to nth node from end.
     * @param n Position from end (1-based).
     * @return T& Data at nth node from end.
     * @throw std::invalid_argument if n <= 0.
     * @throw std::out_of_range if n > size.
     */
    T& nth_from_end(int n);

    /**
     * @brief Detects if the list contains a cycle.
     * @return true if cycle exists, false otherwise.
     */
    bool has_cycle() const;

    /**
     * @brief Removes duplicates from an unsorted list.
     */
    void remove_duplicates();

    /**
     * @brief Checks if the list is a palindrome.
     * @return true if palindrome, false otherwise.
     */
    bool is_palindrome() const;

    /**
     * @brief Computes the length of the list.
     * @return int Number of nodes.
     */
    int length() const;

    /**
     * @brief Reorders list in first->last->second->second_last... pattern.
     */
    void reorder();

    /**
     * @brief Reverses the list in groups of k nodes.
     * @param k The group size to reverse.
     * @throw std::invalid_argument if k <= 0.
     */
    void reverse_k_group(int k);

    //added new here 
       const T& front() const;
    const T& back() const;
};

// Implementation

template <typename T>
SinglyLinkedList<T>::Node::Node(const T& data, Node* next)
    : data(data), next(next) {}


//added new here 
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& other) 
    : head(nullptr), list_size(0) {
    Node* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}

//added new here 
template <typename T>
const T& SinglyLinkedList<T>::front() const {
    if (!head) throw std::underflow_error("List is empty");
    return head->data;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const {
    if (!head) throw std::underflow_error("List is empty");
    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    return curr->data;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), list_size(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
bool SinglyLinkedList<T>::empty() const {
    return list_size == 0;
}

template <typename T>
int SinglyLinkedList<T>::size() const {
    return list_size;
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
    head = new Node(value, head);
    ++list_size;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }
    ++list_size;
}

template <typename T>
void SinglyLinkedList<T>::insert(int index, const T& value) {
    if (index < 0 || index > list_size)
        throw std::out_of_range("Index out of bounds");

    if (index == 0) {
        push_front(value);
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i)
            prev = prev->next;
        prev->next = new Node(value, prev->next);
        ++list_size;
    }
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    if (!head) throw std::underflow_error("List is empty");

    Node* temp = head;
    head = head->next;
    delete temp;
    --list_size;
}

template <typename T>
void SinglyLinkedList<T>::pop_back() {
    if (!head) throw std::underflow_error("List is empty");

    if (!head->next) {
        delete head;
        head = nullptr;
    } else {
        Node* curr = head;
        while (curr->next->next)
            curr = curr->next;

        delete curr->next;
        curr->next = nullptr;
    }
    --list_size;
}

template <typename T>
void SinglyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= list_size)
        throw std::out_of_range("Index out of bounds");

    if (index == 0) {
        pop_front();
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i)
            prev = prev->next;

        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        --list_size;
    }
}

template <typename T>
T& SinglyLinkedList<T>::front() {
    if (!head) throw std::underflow_error("List is empty");
    return head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back() {
    if (!head) throw std::underflow_error("List is empty");

    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    return curr->data;
}

template <typename T>
T& SinglyLinkedList<T>::at(int index) {
    if (index < 0 || index >= list_size)
        throw std::out_of_range("Index out of bounds");

    Node* curr = head;
    for (int i = 0; i < index; ++i)
        curr = curr->next;
    return curr->data;
}

template <typename T>
const T& SinglyLinkedList<T>::at(int index) const {
    if (index < 0 || index >= list_size)
        throw std::out_of_range("Index out of bounds");

    Node* curr = head;
    for (int i = 0; i < index; ++i)
        curr = curr->next;
    return curr->data;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    list_size = 0;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    Node* curr = head;
    std::cout << "[ ";
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "]\n";
}

template <typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {
    Node* curr = head;
    while (curr) {
        if (curr->data == value)
            return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
void SinglyLinkedList<T>::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    head = prev;
}

template <typename T>
bool SinglyLinkedList<T>::remove_value(const T& value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->data == value) {
            if (!prev) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            --list_size;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <typename T>
int SinglyLinkedList<T>::find(const T& value) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->data == value)
            return index;
        current = current->next;
        ++index;
    }
    return -1;
}

template <typename T>
void SinglyLinkedList<T>::append(const SinglyLinkedList<T>& other) {
    Node* current = other.head;
    while (current) {
        push_back(current->data);  // Fixed: was calling insert with only one parameter
        current = current->next;
    }
}

template <typename T>
void SinglyLinkedList<T>::insert_sorted(const T& value) {
    Node* new_node = new Node(value);
    if (!head || value < head->data) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    ++list_size;
}

template <typename T>
bool SinglyLinkedList<T>::is_sorted() const {
    if (!head || !head->next) return true;
    Node* current = head;
    while (current->next) {
        if (current->data > current->next->data)
            return false;
        current = current->next;
    }
    return true;
}

template <typename T>
SinglyLinkedList<T> SinglyLinkedList<T>::slice(int start, int end) const {
    if (start < 0 || end > list_size || start >= end) {
        throw std::out_of_range("Invalid slice indices.");
    }

    SinglyLinkedList<T> result;
    Node* current = head;
    int index = 0;

    while (current && index < end) {
        if (index >= start) {
            result.push_back(current->data);  // Fixed: was calling insert with only one parameter
        }
        current = current->next;
        ++index;
    }
    return result;
}

// template <typename T>
// void SinglyLinkedList<T>::unique() {
//     std::unordered_set<T> seen;
//     Node* current = head;
//     Node* prev = nullptr;

//     while (current) {
//         if (seen.count(current->data)) {
//             Node* to_delete = current;
//             current = current->next;
//             if (prev) {
//                 prev->next = current;
//             } else {
//                 head = current;  // Fixed: handle case when first node is deleted
//             }
//             delete to_delete;
//             --list_size;
//         } else {
//             seen.insert(current->data);
//             prev = current;
//             current = current->next;
//         }
//     }
// }

//added new here 
template <typename T>
void SinglyLinkedList<T>::unique() {
    if (!head) return;
    
    std::unordered_set<T> seen;
    Node* current = head;
    Node* prev = nullptr;
    
    while (current) {
        if (seen.count(current->data)) {
            Node* to_delete = current;
            current = current->next;
            if (prev) {
                prev->next = current;
            } else {
                head = current;
            }
            delete to_delete;
            --list_size;
        } else {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

template <typename T>
typename SinglyLinkedList<T>::Node* SinglyLinkedList<T>::merge_sorted_lists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->data < l2->data) {
        l1->next = merge_sorted_lists(l1->next, l2);
        return l1;
    } else {
        l2->next = merge_sorted_lists(l1, l2->next);
        return l2;
    }
}

template <typename T>
typename SinglyLinkedList<T>::Node* SinglyLinkedList<T>::merge_sort(Node* head) {
    if (!head || !head->next) return head;

    // Find middle
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    Node* left = merge_sort(head);
    Node* right = merge_sort(mid);

    return merge_sorted_lists(left, right);
}

template <typename T>
void SinglyLinkedList<T>::sort() {
    head = merge_sort(head);
}

// template <typename T>
// void SinglyLinkedList<T>::merge(const SinglyLinkedList<T>& other) {
//     // Create a copy of other's list first
//     SinglyLinkedList<T> other_copy;
//     Node* current = other.head;
//     while (current) {
//         other_copy.push_back(current->data);
//         current = current->next;
//     }
    
//     Node* merged = merge_sorted_lists(this->head, other_copy.head);
//     this->head = merged;
//     other_copy.head = nullptr; // Prevent double deletion

//     // Recalculate size
//     list_size = 0;
//     Node* temp = head;
//     while (temp) {
//         ++list_size;
//         temp = temp->next;
//     }
// }

//added here new 
template <typename T>
void SinglyLinkedList<T>::merge(const SinglyLinkedList<T>& other) {
    if (other.empty()) return;
    
    // Create nodes for the merged result
    Node dummy(T{});
    Node* tail = &dummy;
    Node* curr1 = head;
    Node* curr2 = other.head;
    
    // Merge the two sorted lists
    while (curr1 && curr2) {
        if (curr1->data <= curr2->data) {
            tail->next = curr1;
            curr1 = curr1->next;
        } else {
            tail->next = new Node(curr2->data);
            curr2 = curr2->next;
        }
        tail = tail->next;
    }
    
    // Add remaining elements
    while (curr1) {
        tail->next = curr1;
        curr1 = curr1->next;
        tail = tail->next;
    }
    
    while (curr2) {
        tail->next = new Node(curr2->data);
        curr2 = curr2->next;
        tail = tail->next;
    }
    
    head = dummy.next;
    list_size += other.list_size;
} 


template <typename T>
void SinglyLinkedList<T>::rotate_left(int k) {
    if (!head || k <= 0) return;
    k %= list_size;
    if (k == 0) return;

    Node* current = head;
    int count = 1;
    while (count < k && current) {
        current = current->next;
        ++count;
    }

    if (!current || !current->next) return;

    Node* new_head = current->next;
    current->next = nullptr;

    Node* tail = new_head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = head;
    head = new_head;
}

template <typename T>
void SinglyLinkedList<T>::rotate_right(int k) {
    if (!head || k <= 0) return;
    k %= list_size;
    if (k == 0) return;

    rotate_left(list_size - k);
}

template <typename T>
T& SinglyLinkedList<T>::middle() {
    if (!head) throw std::runtime_error("List is empty");

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

template <typename T>
T& SinglyLinkedList<T>::nth_from_end(int n) {
    if (n <= 0) throw std::invalid_argument("n must be positive");

    Node* first = head;
    Node* second = head;

    for (int i = 0; i < n; ++i) {
        if (!first) throw std::out_of_range("n is larger than the list size");
        first = first->next;
    }

    while (first) {
        first = first->next;
        second = second->next;
    }

    return second->data;
}

template <typename T>
bool SinglyLinkedList<T>::has_cycle() const {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

template <typename T>
void SinglyLinkedList<T>::remove_duplicates() {
    if (!head) return;

    std::unordered_set<T> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (seen.count(current->data)) {
            prev->next = current->next;
            delete current;
            current = prev->next;
            --list_size;
        } else {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

template <typename T>
bool SinglyLinkedList<T>::is_palindrome() const {
    std::vector<T> values;
    Node* current = head;

    while (current) {
        values.push_back(current->data);
        current = current->next;
    }

    int i = 0, j = values.size() - 1;
    while (i < j) {
        if (values[i++] != values[j--]) return false;
    }
    return true;
}

template <typename T>
int SinglyLinkedList<T>::length() const {
    int count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

// template <typename T>
// void SinglyLinkedList<T>::reorder() {
//     if (!head || !head->next || !head->next->next) return;

//     // Step 1: Find the middle
//     Node* slow = head;
//     Node* fast = head;
//     while (fast->next && fast->next->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Step 2: Reverse second half
//     Node* prev = nullptr;
//     Node* curr = slow->next;
//     while (curr) {
//         Node* next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     slow->next = nullptr;

//     // Step 3: Merge two halves
//     Node* first = head;
//     Node* second = prev;
//     while (second) {
//         Node* tmp1 = first->next;
//         Node* tmp2 = second->next;
//         first->next = second;
//         second->next = tmp1;
//         first = tmp1;
//         second = tmp2;
//     }
// }

//added new here 
template <typename T>
void SinglyLinkedList<T>::reorder() {
    if (!head || !head->next) return;
    
    // Find middle
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Split the list
    if (prev) prev->next = nullptr;
    
    // Reverse second half
    Node* second_half = slow;
    Node* prev_node = nullptr;
    Node* curr = second_half;
    
    while (curr) {
        Node* next = curr->next;
        curr->next = prev_node;
        prev_node = curr;
        curr = next;
    }
    
    // Merge alternately
    Node* first = head;
    Node* second = prev_node;
    
    while (first && second) {
        Node* tmp1 = first->next;
        Node* tmp2 = second->next;
        
        first->next = second;
        if (tmp1) second->next = tmp1;
        
        first = tmp1;
        second = tmp2;
    }
    
    // Reconnect if we split at middle
    if (!prev) head = prev_node;
}

// template <typename T>
// void SinglyLinkedList<T>::reverse_k_group(int k) {
//     if (k <= 0) throw std::invalid_argument("k must be greater than 0");

//     Node dummy(T{});  // Fixed: provide default value for T
//     dummy.next = head;
//     Node* prevGroupEnd = &dummy;

//     while (true) {
//         Node* kth = prevGroupEnd;
//         for (int i = 0; i < k && kth; ++i)
//             kth = kth->next;
//         if (!kth) break;

//         Node* groupStart = prevGroupEnd->next;
//         Node* nextGroupStart = kth->next;

//         // Reverse group
//         Node* prev = kth->next;
//         Node* curr = groupStart;
//         while (curr != nextGroupStart) {
//             Node* tmp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = tmp;
//         }

//         prevGroupEnd->next = kth;
//         prevGroupEnd = groupStart;
//     }

//     head = dummy.next;
// }

//added new here 
template <typename T>
void SinglyLinkedList<T>::reverse_k_group(int k) {
    if (k <= 0) throw std::invalid_argument("k must be greater than 0");
    if (!head || k == 1) return;
    
    // Count total nodes
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    
    if (count < k) return;
    
    // Use actual node as dummy instead of creating one
    Node* dummy = new Node(head->data);  // Temporary dummy
    dummy->next = head;
    Node* prevGroupEnd = dummy;
    
    while (count >= k) {
        Node* groupStart = prevGroupEnd->next;
        Node* kth = groupStart;
        
        // Find kth node
        for (int i = 1; i < k; ++i)
            kth = kth->next;
        
        Node* nextGroupStart = kth->next;
        
        // Reverse the group
        Node* prev = nextGroupStart;
        Node* curr = groupStart;
        while (curr != nextGroupStart) {
            Node* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        prevGroupEnd->next = kth;
        prevGroupEnd = groupStart;
        count -= k;
    }
    
    head = dummy->next;
    delete dummy;
}
} // namespace data_structures

#endif // SINGLY_LINKED_LIST_HPP