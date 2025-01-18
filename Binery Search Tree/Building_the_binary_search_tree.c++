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

class solution{
public:
    TreeNode* treecreation(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
private:
    TreeNode* build(vector<int>& A, int &i, int upper) {
        if(i == A.size() || A[i] > upper) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(A[i++]);
        root -> left = build(A, i, root -> val);
        root -> right = build(A, i, upper);
        return root;
    }
};