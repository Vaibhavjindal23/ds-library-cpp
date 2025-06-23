#ifndef TREE_HPP
#define TREE_HPP

#include<bits/stdc++.h>
using namespace std;

namespace data_structures {

/**
 * @brief Node class representing each node in the tree.
 */
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val);
};

/**
 * @brief A unified tree class supporting both Binary Tree and Binary Search Tree operations.
 */
/**
 * @brief Represents a unified binary tree and binary search tree.
 * 
 * This class supports both general binary tree operations (like level-order insertion)
 * and binary search tree operations (like BST insertion, deletion, and search).
 */
class Tree {
private:
    /// Root of the tree
    TreeNode* root;

    /** @brief Recursively deletes all nodes in the tree. */
    void destroyTree(TreeNode* node);

    /** 
     * @brief Inserts a value into the binary tree using level-order strategy.
     * @param node Current root node.
     * @param val Value to insert.
     * @return Updated root node after insertion.
     */
    TreeNode* insertLevelOrder(TreeNode* node, int val);

    /** 
     * @brief Inserts a value into the binary search tree.
     * @param node Current root node.
     * @param val Value to insert.
     * @return Updated root node after insertion.
     */
    TreeNode* insertBST(TreeNode* node, int val);

    /** 
     * @brief Deletes a value from the binary search tree.
     * @param node Current root node.
     * @param val Value to delete.
     * @return Updated root node after deletion.
     */
    TreeNode* deleteBST(TreeNode* node, int val);

    /** 
     * @brief Finds the minimum value node in a subtree.
     * @param node Root of the subtree.
     * @return Pointer to the minimum value node.
     */
    TreeNode* findMin(TreeNode* node);

    /**
     * @brief Searches for a value in the BST.
     * @param node Current root node.
     * @param val Value to search for.
     * @return True if found, false otherwise.
     */
    bool searchBST(TreeNode* node, int val);

    /**
     * @brief Inorder traversal (Left, Root, Right).
     * @param node Current node.
     */
    void inorderTraversal(TreeNode* node);

    /**
     * @brief Preorder traversal (Root, Left, Right).
     * @param node Current node.
     */
    void preorderTraversal(TreeNode* node);

    /**
     * @brief Postorder traversal (Left, Right, Root).
     * @param node Current node.
     */
    void postorderTraversal(TreeNode* node);

    /**
     * @brief Calculates the height of the tree.
     * @param node Current node.
     * @return Height of the tree.
     */
    int height(TreeNode* node);

    /**
     * @brief Counts all nodes in the tree.
     * @param node Current node.
     * @return Total number of nodes.
     */
    int countNodes(TreeNode* node);

    /**
     * @brief Checks if the tree is height-balanced.
     * @param node Current node.
     * @return True if balanced, false otherwise.
     */
    bool isBalanced(TreeNode* node);

    /**
     * @brief Checks if the tree is a valid BST.
     * @param node Current node.
     * @param minVal Minimum valid value for current subtree.
     * @param maxVal Maximum valid value for current subtree.
     * @return True if subtree rooted at node is a valid BST.
     */
    bool isBST(TreeNode* node, int minVal, int maxVal);

    int findMax(TreeNode* node);

    void levelOrderTraversal(TreeNode* node);

    int diameter(TreeNode* node, int& maxDiameter);

public:
    /** 
     * @brief Constructor to initialize an empty tree.
     */
    Tree();

    /** 
     * @brief Destructor to free all tree nodes.
     */
    ~Tree();

    /**
     * @brief Inserts a value in binary tree using level-order strategy.
     * @param val Value to insert.
     */
    void insertLevelOrder(int val);

    /**
     * @brief Inserts a value in the binary search tree.
     * @param val Value to insert.
     */
    void insertBST(int val);

    /**
     * @brief Removes a value from the binary search tree.
     * @param val Value to remove.
     */
    void removeBST(int val);

    /**
     * @brief Displays tree nodes using inorder traversal.
     */
    void inorder();

    /**
     * @brief Displays tree nodes using preorder traversal.
     */
    void preorder();

    /**
     * @brief Displays tree nodes using postorder traversal.
     */
    void postorder();

    /**
     * @brief Searches for a value in the binary search tree.
     * @param val Value to search.
     * @return True if found, false otherwise.
     */
    bool search(int val);

    /**
     * @brief Returns the height of the tree.
     * @return Height of the tree.
     */
    int getHeight();

    /**
     * @brief Counts and returns the total number of nodes in the tree.
     * @return Total node count.
     */
    int countAllNodes();

    /**
     * @brief Checks whether the tree is height-balanced.
     * @return True if balanced, false otherwise.
     */
    bool checkBalanced();

    /**
     * @brief Checks whether the tree is a valid Binary Search Tree (BST).
     * @return True if valid BST, false otherwise.
     */
    bool checkBST();
    /**
 * @brief Returns the maximum value in the tree.
 * @return Maximum value.
 */
int getMax();

/**
 * @brief Performs level-order traversal and prints the tree.
 */
void levelOrder();

/**
 * @brief Checks whether the tree is complete (all levels except last are full and nodes left-aligned).
 * @return True if complete, false otherwise.
 */
bool isComplete();

/**
 * @brief Calculates the diameter (longest path between any two nodes).
 * @return Diameter of the tree.
 */
int diameter();

/**
 * @brief Converts the tree to its mirror.
 */
void mirror();

/**
 * @brief Helper function to recursively mirror the tree.
 * @param node Current node being processed.
 */
void mirror(TreeNode* node);

/**
 * @brief Returns kth smallest element in BST.
 * @param k The kth position.
 * @return The kth smallest value.
 */
int kthSmallest(int k);

/**
 * @brief Returns kth largest element in BST.
 * @param k The kth position.
 * @return The kth largest value.
 */
int kthLargest(int k);

/**
 * @brief Finds Lowest Common Ancestor of two values.
 * @param val1 First node value.
 * @param val2 Second node value.
 * @return The LCA node's value.
 */
int lowestCommonAncestor(int val1, int val2);

/**
 * @brief Helper for LCA finding.
 * @param node Current root.
 * @param val1 First value.
 * @param val2 Second value.
 * @return TreeNode* to the LCA.
 */
TreeNode* LCA(TreeNode* node, int val1, int val2);

/**
 * @brief Returns floor (largest value ≤ given) in BST.
 * @param val The value to find floor for.
 * @return The floor value or -1 if not found.
 */
int floorInBST(int val);

/**
 * @brief Returns ceil (smallest value ≥ given) in BST.
 * @param val The value to find ceil for.
 * @return The ceil value or -1 if not found.
 */
int ceilInBST(int val);

/**
 * @brief Finds inorder predecessor of a given key in BST.
 * @param key Target key.
 * @return Predecessor value or -1 if not found.
 */
int inorderPredecessor(int key);

/**
 * @brief Finds inorder successor of a given key in BST.
 * @param key Target key.
 * @return Successor value or -1 if not found.
 */
int inorderSuccessor(int key);

/**
 * @brief Prints all root-to-leaf paths in the binary tree.
 */
void printRootToLeafPaths();

/**
 * @brief Helper for printing all root-to-leaf paths.
 * @param node Current node.
 * @param path Path from root to current node.
 */
void printPaths(TreeNode* node, std::vector<int>& path);

/**
 * @brief Prints the left view of the binary tree.
 */
void leftView();

/**
 * @brief Prints the right view of the binary tree.
 */
void rightView();

/**
 * @brief Performs zigzag (spiral) level-order traversal.
 */
void zigzagTraversal();

/**
 * @brief Returns the pair of nodes forming the tree's diameter.
 * @return Pair of values representing the endpoints of the longest path.
 */
std::pair<int, int> diameterEndpoints();

/**
 * @brief Returns the maximum path sum from any node to any node.
 * @return The maximum path sum.
 */
int maxPathSum();

};


TreeNode::TreeNode(int val) {
    data = val;
    left = right = nullptr;
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void Tree::insertLevelOrder(int val) {
    root = insertLevelOrder(root, val);
}

TreeNode* Tree::insertLevelOrder(TreeNode* node, int val) {
    if (!node) return new TreeNode(val);
    queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        TreeNode* temp = q.front(); q.pop();
        if (!temp->left) {
            temp->left = new TreeNode(val);
            break;
        } else {
            q.push(temp->left);
        }
        if (!temp->right) {
            temp->right = new TreeNode(val);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return node;
}

void Tree::insertBST(int val) {
    root = insertBST(root, val);
}

TreeNode* Tree::insertBST(TreeNode* node, int val) {
    if (!node) return new TreeNode(val);
    if (val < node->data) node->left = insertBST(node->left, val);
    else node->right = insertBST(node->right, val);
    return node;
}

void Tree::removeBST(int val) {
    root = deleteBST(root, val);
}

TreeNode* Tree::deleteBST(TreeNode* node, int val) {
    if (!node) return nullptr;
    if (val < node->data)
        node->left = deleteBST(node->left, val);
    else if (val > node->data)
        node->right = deleteBST(node->right, val);
    else {
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        } else {
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteBST(node->right, temp->data);
        }
    }
    return node;
}

TreeNode* Tree::findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

bool Tree::search(int val) {
    return searchBST(root, val);
}

bool Tree::searchBST(TreeNode* node, int val) {
    if (!node) return false;
    if (node->data == val) return true;
    if (val < node->data) return searchBST(node->left, val);
    return searchBST(node->right, val);
}

void Tree::inorder() {
    inorderTraversal(root);
    cout << endl;
}

void Tree::inorderTraversal(TreeNode* node) {
    if (!node) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void Tree::preorder() {
    preorderTraversal(root);
    cout << endl;
}

void Tree::preorderTraversal(TreeNode* node) {
    if (!node) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void Tree::postorder() {
    postorderTraversal(root);
    cout << endl;
}

void Tree::postorderTraversal(TreeNode* node) {
    if (!node) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

int Tree::getHeight() {
    return height(root);
}

int Tree::height(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int Tree::countAllNodes() {
    return countNodes(root);
}

int Tree::countNodes(TreeNode* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

bool Tree::checkBalanced() {
    return isBalanced(root);
}

bool Tree::isBalanced(TreeNode* node) {
    if (!node) return true;
    int lh = height(node->left);
    int rh = height(node->right);
    return abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

bool Tree::checkBST() {
    return isBST(root, INT_MIN, INT_MAX);
}

bool Tree::isBST(TreeNode* node, int minVal, int maxVal) {
    if (!node) return true;
    if (node->data <= minVal || node->data >= maxVal) return false;
    return isBST(node->left, minVal, node->data) && isBST(node->right, node->data, maxVal);
}
int Tree::getMax() {
    return findMax(root);
}

int Tree::findMax(TreeNode* node) {
    if (!node) return INT_MIN;
    return max({node->data, findMax(node->left), findMax(node->right)});
}
void Tree::levelOrder() {
    levelOrderTraversal(root);
    cout << endl;
}

void Tree::levelOrderTraversal(TreeNode* node) {
    if (!node) return;
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}
bool Tree::isComplete() {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool end = false;

    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        if (curr) {
            if (end) return false;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            end = true;
        }
    }
    return true;
}
int Tree::diameter() {
    int maxDiameter = 0;
    diameter(root, maxDiameter);
    return maxDiameter;
}

int Tree::diameter(TreeNode* node, int& maxDiameter) {
    if (!node) return 0;
    int lh = diameter(node->left, maxDiameter);
    int rh = diameter(node->right, maxDiameter);
    maxDiameter = max(maxDiameter, lh + rh);
    return 1 + max(lh, rh);
}

void data_structures::Tree::mirror() {
    mirror(root);
}

void data_structures::Tree::mirror(TreeNode* node) {
    if (!node) return;
    swap(node->left, node->right);
    mirror(node->left);
    mirror(node->right);
}
int data_structures::Tree::kthSmallest(int k) {
    TreeNode* curr = root;
    stack<TreeNode*> st;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        if (--k == 0) return curr->data;
        curr = curr->right;
    }
    return -1; // Not found
}

int data_structures::Tree::kthLargest(int k) {
    TreeNode* curr = root;
    stack<TreeNode*> st;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->right;
        }
        curr = st.top(); st.pop();
        if (--k == 0) return curr->data;
        curr = curr->left;
    }
    return -1; // Not found
}

int data_structures::Tree::lowestCommonAncestor(int val1, int val2) {
    TreeNode* lca = LCA(root, val1, val2);
    return lca ? lca->data : -1;
}

TreeNode* data_structures::Tree::LCA(TreeNode* node, int val1, int val2) {
    if (!node) return nullptr;

    if (node->data > val1 && node->data > val2)
        return LCA(node->left, val1, val2);
    if (node->data < val1 && node->data < val2)
        return LCA(node->right, val1, val2);

    return node;
}
int data_structures::Tree::floorInBST(int val) {
    TreeNode* curr = root;
    int res = -1;
    while (curr) {
        if (curr->data == val) return val;
        if (curr->data < val) {
            res = curr->data;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return res;
}
int data_structures::Tree::ceilInBST(int val) {
    TreeNode* curr = root;
    int res = -1;
    while (curr) {
        if (curr->data == val) return val;
        if (curr->data > val) {
            res = curr->data;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return res;
}
int data_structures::Tree::inorderPredecessor(int key) {
    TreeNode* curr = root;
    int pred = -1;
    while (curr) {
        if (curr->data < key) {
            pred = curr->data;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return pred;
}
int data_structures::Tree::inorderSuccessor(int key) {
    TreeNode* curr = root;
    int succ = -1;
    while (curr) {
        if (curr->data > key) {
            succ = curr->data;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return succ;
}
void data_structures::Tree::printRootToLeafPaths() {
    vector<int> path;
    printPaths(root, path);
}

void data_structures::Tree::printPaths(TreeNode* node, vector<int>& path) {
    if (!node) return;
    path.push_back(node->data);
    if (!node->left && !node->right) {
        for (int val : path) cout << val << " ";
        cout << endl;
    } else {
        printPaths(node->left, path);
        printPaths(node->right, path);
    }
    path.pop_back();
}
void data_structures::Tree::leftView() {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    cout << endl;
}
void data_structures::Tree::rightView() {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    cout << endl;
}
void data_structures::Tree::zigzagTraversal() {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            int idx = leftToRight ? i : sz - 1 - i;
            level[idx] = node->data;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        for (int val : level) cout << val << " ";
        leftToRight = !leftToRight;
    }
    cout << endl;
}
pair<int, int> data_structures::Tree::diameterEndpoints() {
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    int maxLen = -1;

    function<int(TreeNode*, TreeNode*&)> dfs = [&](TreeNode* node, TreeNode*& deepest) -> int {
        if (!node) return 0;
        TreeNode* leftDeep = nullptr;
        TreeNode* rightDeep = nullptr;
        int lh = dfs(node->left, leftDeep);
        int rh = dfs(node->right, rightDeep);

        if (lh + rh > maxLen) {
            maxLen = lh + rh;
            node1 = leftDeep ? leftDeep : node;
            node2 = rightDeep ? rightDeep : node;
        }

        deepest = (lh > rh ? leftDeep : rightDeep);
        if (!deepest) deepest = node;
        return 1 + max(lh, rh);
    };

    TreeNode* dummy = nullptr;
    dfs(root, dummy);
    return { node1 ? node1->data : -1, node2 ? node2->data : -1 };
}
int data_structures::Tree::maxPathSum() {
    int maxSum = INT_MIN;

    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        maxSum = max(maxSum, left + right + node->data);
        return max(left, right) + node->data;
    };

    dfs(root);
    return maxSum;
}

} // namespace data_structures

#endif
