#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data) {
        this -> data  = data;
        right = left = nullptr;
    }
};

class Solution {
    // Function to calculate the height of the tree
    int height_of_tree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int right = height_of_tree(root -> right);
        int left = height_of_tree(root -> left);
        
        return max(left, right) + 1;
    }
    
    // Function to traverse each node and calculate the diameter
    void traverse(TreeNode* root, int &max2) {
        if (root == nullptr) return;
        
        // Calculate the height of the left and right subtrees
        int maximum = height_of_tree(root->left) + height_of_tree(root->right);
        
        // Update the maximum diameter
        max2 = max(maximum, max2);
        
        // Traverse the left and right subtrees
        traverse(root->left, max2);
        traverse(root->right, max2);
    }
    
public:
    // Function to return the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int max2 = 0;
        traverse(root, max2);
        return max2;
    }
};
