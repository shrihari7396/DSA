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

class Solution {
private:
    bool get_path(TreeNode* root, vector<int>& arr, int x) {
        if(root == nullptr) return false;

        arr.emplace_back(root -> val);

        if(root -> val == x ) {
            return true;
        }

        if(get_path(root -> left, arr, x) || get_path(root -> right, arr, x)) return true;

        arr.pop_back();
        return false;
    }

    void get_all_path(TreeNode* root, vector<vector<int>>& ans, vector<int>& level) {
        if(root == nullptr) return;

        level.emplace_back(root -> val);
        if(root -> left == nullptr && root -> right == nullptr) {
            ans.emplace_back(root -> val);
        }

        get_all_path(root -> left, ans,level);
        get_all_path(root -> right, ans, level);
        level.pop_back();
    }
public:
    vector<vector<int>> list_traversal(TreeNode* root) {
    vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }
    vector<int> level;
    get_all_path(root, ans, level);
    return ans;
    }
};

