#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode * right, * left;
    TreeNode (int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

class Solution {
private:
    int maximum_path_sum(TreeNode* root, int &total_sum) {
        if(root == nullptr) return 0;
        int left = max(0,maximum_path_sum(root -> left,total_sum));
        int right = max(0, maximum_path_sum(root -> right, total_sum));
        total_sum = max(total_sum,left+right+root->data);
        return max(left, right) + root -> data;
    }
public:
    int maxPathlenght(TreeNode* root) {
        int max = INT_MIN;
        int temp = maximum_path_sum(root, max);
        return max;
    }
};