#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

class Soloution {
public:
    vector<int> rightViewofTree(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if(i == size-1) ans.emplace_back(temp -> data);
                
                if(temp -> left != nullptr) q.push(temp -> left);

                if(temp -> right != nullptr) q.push(temp -> right);
 
            }         
        }
        return ans;
    }

};