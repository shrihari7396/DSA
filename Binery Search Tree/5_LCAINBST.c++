#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this -> val = val;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

class Solution{
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return nullptr;
        }

        if(root -> val > p -> val && root -> val > q -> val) {
            return LCA(root -> left, p, q);
        } else if(root -> val < p -> val && root -> val < q -> val) {
            return LCA(root -> right, p, q);
        }
        return root;
    }
};

int main(int argv, char** argc) {

    return 0;
}