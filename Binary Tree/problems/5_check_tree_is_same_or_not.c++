#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

class Solution {
public:
    bool check_tree_is_same_or_not(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root2 == nullptr || root1 == nullptr) return false;
        return (root1 -> data == root2 -> data) && check_tree_is_same_or_not(root1 -> left, root2 -> left) && check_tree_is_same_or_not(root1 -> right, root2 -> right);
    }
};