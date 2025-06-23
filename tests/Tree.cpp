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

#include "../data_structures/Tree.hpp"
using namespace data_structures;

// Utility function for section headers
void printSection(const string& title) {
    cout << "\n==================== " << title << " ====================\n";
}

// Test insertion and traversals
void testInsertionAndTraversals() {
    Tree t;

    // Insert into Binary Search Tree
    vector<int> values = { 50, 30, 70, 20, 40, 60, 80 };
    for (int val : values)
        t.insertBST(val);

    printSection("Inorder Traversal (Should be sorted)");
    t.inorder();

    printSection("Preorder Traversal");
    t.preorder();

    printSection("Postorder Traversal");
    t.postorder();

    printSection("Level Order Traversal");
    t.levelOrder();
}

// Test search and delete
void testSearchAndDelete() {
    Tree t;
    for (int val : { 40, 20, 60, 10, 30, 50, 70 })
        t.insertBST(val);

    printSection("Initial Inorder");
    t.inorder();

    printSection("Search 30 and 100");
    cout << "Search 30: " << (t.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (t.search(100) ? "Found" : "Not Found") << endl;

    printSection("Deleting 20");
    t.removeBST(20);
    t.inorder();
}

// Test structural properties
void testTreeProperties() {
    Tree t;
    for (int val : { 10, 5, 15, 3, 7, 13, 18 })
        t.insertBST(val);

    printSection("Tree Height");
    cout << "Height: " << t.getHeight() << endl;

    printSection("Node Count");
    cout << "Total Nodes: " << t.countAllNodes() << endl;

    printSection("Check Balanced");
    cout << "Is Balanced: " << (t.checkBalanced() ? "Yes" : "No") << endl;

    printSection("Is BST");
    cout << "Is BST: " << (t.checkBST() ? "Yes" : "No") << endl;

    printSection("Is Complete");
    cout << "Is Complete: " << (t.isComplete() ? "Yes" : "No") << endl;
}

// Test advanced features
void testAdvancedOperations() {
    Tree t;
    for (int val : { 50, 30, 70, 20, 40, 60, 80 })
        t.insertBST(val);

    printSection("Mirror Tree");
    t.mirror();
    t.inorder();

    printSection("Restore Original (Mirror again)");
    t.mirror();
    t.inorder();

    printSection("Kth Smallest and Largest");
    cout << "3rd Smallest: " << t.kthSmallest(3) << endl;
    cout << "2nd Largest: " << t.kthLargest(2) << endl;

    printSection("Lowest Common Ancestor of 20 and 40");
    cout << "LCA: " << t.lowestCommonAncestor(20, 40) << endl;

    printSection("Floor and Ceil");
    cout << "Floor of 55: " << t.floorInBST(55) << endl;
    cout << "Ceil of 55: " << t.ceilInBST(55) << endl;

    printSection("Predecessor and Successor of 50");
    cout << "Inorder Predecessor: " << t.inorderPredecessor(50) << endl;
    cout << "Inorder Successor: " << t.inorderSuccessor(50) << endl;
}

// Test visual and path-related outputs
void testVisualAndPaths() {
    Tree t;
    for (int val : { 10, 6, 15, 3, 8, 12, 18 })
        t.insertBST(val);

    printSection("Root to Leaf Paths");
    t.printRootToLeafPaths();

    printSection("Left View");
    t.leftView();

    printSection("Right View");
    t.rightView();

    printSection("Zigzag Traversal");
    t.zigzagTraversal();
}

// Test diameter and max path sum
void testTreeDiameterAndPathSum() {
    Tree t;
    for (int val : { 10, 5, 20, 3, 7, 30 })
        t.insertBST(val);

    printSection("Tree Diameter");
    cout << "Diameter Length: " << t.diameter() << endl;

    printSection("Diameter Endpoints");
    printSection("Diameter Endpoints");
    auto endpoints = t.diameterEndpoints();
    cout << "Endpoints: " << endpoints.first << " and " << endpoints.second << endl;


    printSection("Maximum Path Sum");
    cout << "Max Path Sum: " << t.maxPathSum() << endl;
}

int main() {
    testInsertionAndTraversals();
    testSearchAndDelete();
    testTreeProperties();
    testAdvancedOperations();
    testVisualAndPaths();
    testTreeDiameterAndPathSum();
    cout<<"ALL tests completed.";
    return 0;
}
