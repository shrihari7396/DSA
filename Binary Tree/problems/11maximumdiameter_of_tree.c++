#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val) {
        this -> val = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int maximumdiameterofTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        int ans = 0;
        q.push({root, 0});
        while(!q.empty()) {
            unsigned int size = q.size();
            unsigned int mmin = q.front().second;
            unsigned int first, last;
            for(int i = 0; i < size; i++) {
                TreeNode* current_node = q.front().first;
                int current_num = q.front().second;
                q.pop();
                if(i == 0) first = current_num;
                if(i == size-1) last = current_num;
                if(current_node -> left != nullptr) {
                    q.push({current_node, 2*current_num + 1});
                }
                if(current_node -> right != nullptr) {
                    q.push({current_node -> right, 2*current_num+2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }

};
unsigned long long

int main(void) {

    return 0;
}