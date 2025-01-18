#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val) {
        this -> val = val;
        right = left = nullptr;
    }
};

// mine 

class Solution {
public:
vector<vector<int>> zig_zag_traversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        vector<int> level;
        int size = q.size();
        for(int i = 0; i < size; i++) {
            TreeNode* tree = q.front();
            q.pop();
            if(tree -> right != nullptr) q.push(tree -> right);
            if(tree -> left != nullptr) q.push(tree -> left);
            level.emplace_back(tree -> val);
        }
        ans.emplace_back(level);
    }   
    int size1 = ans.size();
    for(int i = 0; i < size1; i++) {
        if(i % 2 != 0) {
            reverse(ans.begin(), ans.end());
        }
    }
    return ans;
}   
};

// striver

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = node -> val;
                if(node -> left != nullptr) q.push(node -> left);
                if(node -> right != nullptr) q.push(node -> right);
            }
            leftToRight = !leftToRight;
            result.emplace_back(row); 
        }
        return result;
    }
};
