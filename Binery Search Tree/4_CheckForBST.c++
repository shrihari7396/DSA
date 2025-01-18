#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) {
        val = x;
        right = left = nullptr;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
        // Base case: an empty tree is a valid BST
        if (!root) return true;

        // Check the current node's value against the allowed range
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Recursively check the left and right subtrees, updating the range
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
};
