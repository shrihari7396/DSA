#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data) {
        val = data;
        right = left = nullptr;
    }
};


// My solution
class Solution {
    bool path(TreeNode* root, TreeNode* x, vector<TreeNode*>& level) {
        if(root == nullptr) return false;
        level.emplace_back(root);
        if(root == x) return true;
        if(path(root -> left, x, level) || path(root -> right, x, level)) {
            return true;
        }
        level.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1;
        vector<TreeNode*> q1;
        if(root == nullptr) return root;
        bool p2 = path(root, p, p1);
        bool q2 = path(root, q, q1);
        int p3 = p1.size();
        int q3 = q1.size();
        int final = 0;
        if(p3 < q3) {
            final = p3;
        } else {
            final = q3;
        }
        for(int i = 1; i < final; i++) {
            if(p1[i] != q1[i]) {
                return p1[i-1];   
            }
        }
        return p1[final-1];
    }
};

// striver Solution
class Solution_s {
    TreeNode* LCA (TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
};