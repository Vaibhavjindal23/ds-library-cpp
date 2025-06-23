/**
 * 📌 How to Run This File in Gitpod Terminal:
 * 
 * 👉 Step 1: Make sure you're in the root directory.
 * 👉 Step 2: Compile the file using:
 *     g++ -std=c++17 tests/main.cpp -o run && ./run
 * 
 *    This will compile and execute the main demo file 
 *    for testing multiple data structures from the DSHub++ library.
 */


#include "../data_structures/data_structures.hpp"
using namespace data_structures;

int main() {
    Trie t;
    t.insert("hello");
    t.insert("world");
    cout << "StartsWith 'worl': " << t.startsWith("worl") << endl;
    Tree tree;
    tree.insertBST(10);
    tree.inorder();
     
    return 0;
}
