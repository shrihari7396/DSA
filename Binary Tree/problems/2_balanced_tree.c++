#include <bits/stdc++.h>
using namespace std;

// Class definition for the tree node
class Node {
public:
    int data;
    Node* right;
    Node* left;
    // Constructor to initialize node data and set children to nullptr
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    // Helper function to calculate the height of the tree and detect imbalance
    int height(Node* root) {
        // Base case: if the current node is null, return height as 0
        if (root == nullptr) return 0;
        
        // Recursively calculate the height of the left subtree
        int l = height(root->left);
        // If the left subtree is imbalanced, propagate -1 upwards
        if (l == -1) return -1;
        
        // Recursively calculate the height of the right subtree
        int r = height(root->right);
        // If the right subtree is imbalanced, propagate -1 upwards
        if (r == -1) return -1;
        
        // If the difference in heights of left and right subtrees is greater than 1, return -1
        if (abs(l - r) > 1) return -1;
        
        // Return the height of the current node as the maximum of the two subtrees plus 1
        return max(l, r) + 1;
    }
    
public:
    // Function to check if the tree is balanced
    bool isBalanced(Node* root) {
        // Call the height function and check if it returns -1 (imbalanced)
        return height(root) != -1;
    }
};
