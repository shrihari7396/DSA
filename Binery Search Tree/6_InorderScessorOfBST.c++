#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int val) {
        this -> val = val;
        left = right = nullptr;
    }
};

class Solution{
public:
    TreeNode* findScessor(TreeNode* root, TreeNode* target) {
        TreeNode *sucessor = nullptr;
        while(!root) {
            if(root -> val <= target -> val) {
                root = root -> right;
            } else {
                sucessor = root;
                root = root -> left;
            }
        }
        return sucessor;
    }
};

int main(int argv, char** argc) {
    return 0;
}