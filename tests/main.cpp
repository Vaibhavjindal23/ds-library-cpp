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
