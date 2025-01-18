#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data) {
        this -> data = data;
        right = left = NULL;
    }
};

class Solution {
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &Parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if(current -> left) {
                Parent_track[current->left]  = current;
                queue.push(current-> left);
            }
            if(current -> right) {
                Parent_track[current -> right] = current;
                queue.push(current -> right);
            }
        }
    }

public:
    vector<int> distancek(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        markParent(root, m, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) {
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if(current -> left && !visited[current -> left]) {
                    queue.push(current->left);
                    visited[current -> left] = true;
                }
                if(current -> right && !visited[current -> right]) {
                    queue.push(current -> right);
                    visited[current -> right] = true;
                }
                if(m[current] && !visited[current]) {
                    queue.push(m[current]);
                    visited[m[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.emplace_back(current -> data);
        }
        return result;
    }
};
