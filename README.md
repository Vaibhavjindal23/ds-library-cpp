# 📚 Data Structures C++ Library

A highly modular, templated C++ library implementing essential and advanced data structures under a unified `data_structures` namespace. Designed for **education**, **research**, and **production-level systems**, it features clean organization, extensive Doxygen-style documentation, and extensibility.

---

## ✍️ Author

**Created by**: Vaibhav Jindal  
**Degree**: B.Tech CSE Core, VIT Bhopal  
**Namespace**: `data_structures` 📦

---

## 📦 Supported Libraries

---

### ✅ 1. `Array<T>` — Dynamic Array with 60+ Utility Methods

A powerful, templated dynamic array implementation that mimics and extends `std::vector`.

#### 🔧 Features

- Generic templated container
- Dynamic resizing
- Bounds-checked access
- Mathematical: `sum`, `average`, `median`, `mode`, `gcd`, `lcm`, etc.
- Statistical: `standard_deviation`, `range`, prefix/cumulative utilities
- Advanced: `lower_bound`, `kth_smallest`, `subarray_sum_equals`
- Set logic: unique finder, duplicate remover
- Pattern checks: palindrome, AP/GP validation
- Utility: merge sorted arrays, zigzag arrangement, missing number finder

#### 📋 Categorized Method Table

| Category            | Key Methods                                                             |
| ------------------- | ----------------------------------------------------------------------- |
| Construction        | `Array()`, `~Array()`, `clear()`                                        |
| Size/Capacity       | `size()`, `get_capacity()`                                              |
| Access              | `operator[]`, `print()`                                                 |
| Modification        | `push_back()`, `pop_back()`, `insert()`, `remove()`, `fill()`, `swap()` |
| Search/Check        | `find()`, `contains()`, `count()`, `is_sorted()`, `is_palindrome()`     |
| Sorting/Rotation    | `sort()`, `reverse()`, `rotate_left()`, `rotate_right()`, `zigzag()`    |
| Math/Stats          | `sum()`, `average()`, `median()`, `mode()`, `gcd()`, `lcm()`, `range()` |
| Advanced Queries    | `lower_bound()`, `upper_bound()`, `floor_element()`, `ceil_element()`   |
| Set Operations      | `remove_duplicates()`, `find_unique()`, `merge_sorted()`                |
| Progression Checks  | `is_arithmetic_progression()`, `is_geometric_progression()`             |
| Prefix/Suffix Logic | `prefix_sum_array()`, `cumulative_product()`                            |
| Kth Elements        | `kth_smallest()`, `kth_largest()`                                       |
| Subarray/Pattern    | `subarray_sum_equals()`, `find_missing_number()`                        |

---

### ✅ 2. `Tree` — Unified Binary Tree + Binary Search Tree

A class that supports both Binary Tree and BST operations with rich utility.

#### 🌲 Features

- Level-order and BST insertions
- Inorder, preorder, postorder, level-order, zigzag traversals
- Full support for deletion, searching, balancing, completeness
- Advanced utilities: height, diameter, LCA, predecessor/successor, views
- Analytics: node count, max path sum, root-to-leaf paths

#### 📋 Tree Functional Overview

| Category             | Key Methods                                                                 |
|----------------------|------------------------------------------------------------------------------|
| Construction         | `Tree()`, `~Tree()`                                                          |
| Insertion            | `insertLevelOrder(val)`, `insertBST(val)`                                   |
| Deletion             | `removeBST(val)`                                                             |
| Traversals           | `inorder()`, `preorder()`, `postorder()`, `levelOrder()`, `zigzagTraversal()`|
| Property Checks      | `checkBST()`, `checkBalanced()`, `isComplete()`                              |
| Search               | `search(val)`, `getMax()`                                                    |
| Kth Element (BST)    | `kthSmallest(k)`, `kthLargest(k)`                                            |
| Floor/Ceil (BST)     | `floorInBST(val)`, `ceilInBST(val)`                                          |
| Predecessor/Successor| `inorderPredecessor(key)`, `inorderSuccessor(key)`                           |
| Path Utilities       | `printRootToLeafPaths()`, `lowestCommonAncestor(v1, v2)`                     |
| Analytics            | `countAllNodes()`, `getHeight()`, `diameter()`, `diameterEndpoints()`        |
| Views                | `leftView()`, `rightView()`                                                  |
| Transformations      | `mirror()`                                                                   |
| Path Sums            | `maxPathSum()`                                                               |

---

### ✅ 3. `DisjointSet` — Union-Find with Path Compression

Efficient disjoint set (Union-Find) data structure with multiple optimizations.

#### 🔧 Features

- `find()` with path compression
- `unionByRank()` and `unionBySize()`
- Efficient `isConnected()` queries
- Set size queries and reset support

#### 📋 Functional Overview

| Category            | Key Methods                           |
|---------------------|----------------------------------------|
| Initialization      | `DisjointSet(n)`                       |
| Find Operations     | `find(u)`                              |
| Union Operations    | `unionByRank(u, v)`, `unionBySize(u, v)` |
| Set Queries         | `getSetSize(u)`, `isConnected(u, v)`   |
| Reset               | `reset()`                              |

---

### ✅ 4. `Queue<T>` — Circular Dynamic Generic Queue

A dynamic, circular buffer-based templated queue with constant-time operations.

#### 🔧 Features

- Dynamic circular array
- Constant-time enqueue/dequeue
- Access front and rear
- Bounds-safe access
- Auto-resizing on overflow
- Templated for any `T`

#### 📋 Queue Functional Overview

| Category         | Key Methods                              |
|------------------|-------------------------------------------|
| Construction     | `Queue()`, `~Queue()`                     |
| Access           | `front()`, `back()`                       |
| Modification     | `enqueue(val)`, `dequeue()`               |
| Query            | `size()`, `empty()`                       |
| Utility          | `print()`, `clear()`                      |

---

---

### ✅ 5. `Graph` — Weighted Graph (Directed/Undirected) with Algorithms

A comprehensive graph class supporting both **adjacency list** and **adjacency matrix** representations, and a rich suite of classic graph algorithms.

#### 🌐 Features

- Supports directed and undirected graphs with weighted edges
- Dual internal representations: adjacency list and matrix
- Includes DFS, BFS, Dijkstra, Bellman-Ford, Floyd-Warshall
- Topological sort, cycle detection, bipartite check
- SCC (Strongly Connected Components) using Kosaraju's algorithm
- Graph utilities like degree, transposition, edge/vertex manipulation

#### 📋 Graph Functional Overview

| Category             | Key Methods                                                              |
|----------------------|---------------------------------------------------------------------------|
| Construction         | `Graph(vertices)`                                                        |
| Edge Operations      | `addEdge(u, v, w)`, `removeEdge(u, v)`, `edgeExists(u, v)`               |
| Vertex Utilities     | `removeVertex(v)`, `getNeighbors(u)`, `outDegree(u)`                     |
| Traversals           | `BFS(start)`, `DFS(start)`, `printAdjList()`, `printAdjMatrix()`         |
| Path Algorithms      | `dijkstra(start)`, `bellmanFord(start)`, `floydWarshall()`               |
| MST Algorithms       | `primMST()`                                                              |
| Connectivity Checks  | `hasCycleDirected()`, `hasCycleUndirected()`, `countConnectedComponents()` |
| Sorting/Order        | `topologicalSort()`                                                      |
| Bipartiteness        | `isBipartite()`                                                          |
| SCC Detection        | `getSCCs()`                                                              |
| Transformations      | `getTranspose()`, `makeUndirected()`, `clear()`                          |

---

### ✅ 6. `Stack<T>` — Generic Stack using Custom Array

A robust template-based **LIFO Stack** implementation built on top of the custom `Array<T>` class. Includes additional methods beyond the standard STL stack.

#### 📦 Features

- Push, pop, top with bounds checking
- Full access to stack elements by index or vector conversion
- Access to top and bottom of stack
- Equality comparison and swap support
- Fully templated for custom types

#### 📋 Stack Functional Overview

| Category            | Key Methods                                                      |
|---------------------|------------------------------------------------------------------|
| Construction        | `Stack()`                                                        |
| Basic Operations    | `push(val)`, `pop()`, `top()`, `bottom()`                        |
| Query               | `size()`, `empty()`, `clear()`                                   |
| Access              | `at(i)`, `top()`, `bottom()`                                     |
| Comparison/Swap     | `operator==(other)`, `swap(other)`                               |
| Conversion          | `to_vector()`                                                    |
| Transformation      | `reverse()`, `print()`                                           |

---

---

### ✅ 7. `Trie` — Prefix Tree for Efficient Word Storage & Search

A compact and powerful **prefix tree** implementation for fast word search, autocomplete, and prefix queries.

#### 🔡 Features

- Insertion, exact word search, and prefix-based search
- Word removal with memory cleanup
- Count of all words and prefix matches
- Longest common prefix computation
- Retrieve all stored words or those with a specific prefix

#### 📋 Trie Functional Overview

| Category            | Key Methods                                                             |
|---------------------|--------------------------------------------------------------------------|
| Construction        | `Trie()`, `~Trie()`                                                      |
| Word Operations     | `insert(word)`, `remove(word)`, `search(word)`                          |
| Prefix Operations   | `startsWith(prefix)`, `countPrefix(prefix)`, `longestCommonPrefix()`    |
| Listing             | `listAllWords()`, `listWordsWithPrefix(prefix)`                         |
| Utility             | `countWords()`, `isEmpty()`                                              |

---

### ✅ 8. `SinglyLinkedList<T>` — Generic Forward Linked List

A fully-featured singly linked list class offering both **basic and advanced utilities**, ideal for learning and system-level design.

#### 🔗 Features

- Dynamic memory-safe singly linked list
- Full support for indexed access, insertion, and deletion
- Extended utilities: slicing, palindrome check, cycle detection, reordering
- Sorting (merge sort), rotation, deduplication
- Added STL-like behavior (size, at, contains, clear)

#### 📋 Linked List Functional Overview

| Category            | Key Methods                                                                       |
|---------------------|------------------------------------------------------------------------------------|
| Construction        | `SinglyLinkedList()`, `~SinglyLinkedList()`                                       |
| Access              | `front()`, `back()`, `at(i)`, `length()`                                           |
| Modification        | `push_front()`, `push_back()`, `insert(i, val)`, `pop_front()`, `pop_back()`, `remove(i)` |
| Checks              | `empty()`, `contains(val)`, `is_sorted()`, `is_palindrome()`, `has_cycle()`       |
| Search              | `find(val)`, `nth_from_end(n)`, `middle()`                                        |
| Sorting             | `sort()`, `insert_sorted(val)`, `merge(other)`                                    |
| Advanced Ops        | `reverse()`, `reverse_k_group(k)`, `rotate_left(k)`, `rotate_right(k)`            |
| Structural Ops      | `clear()`, `unique()`, `remove_duplicates()`, `remove_value(val)`                 |
| Substructure        | `slice(start, end)`, `append(other)`, `reorder()`                                 |
| Printing            | `print()`                                                                          |

---


✅ Installation & Usage
To use the entire library, simply include individual headers as needed:
#include "Array.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Trie.hpp"
#include "Tree.hpp"
#include "Singly_Linked_List.hpp"
#include "graph.hpp"
#include "disjointset.hpp"

Or include all at once using your umbrella header (recommended):

#include "data_structures.hpp"  // [Create this file to include all headers]

📧 Contact
For doubts, collaborations, or feedback:
📩 Email: jindalvaibhav63@gmail.com
🔗 LinkedIn: https://www.linkedin.com/in/vaibhav-jindal-b1b917250/


This project is open-source.
You’re free to use, modify, and distribute it for educational, research, or production purposes.

🌟 Acknowledgments
This library is inspired by academic and industrial standards for reusable C++ components.
It is proudly developed as part of a core data structures suite by Vaibhav Jindal, B.Tech CSE, VIT Bhopal.
