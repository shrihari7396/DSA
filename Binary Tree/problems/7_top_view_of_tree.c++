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

class Node{
public:
    int data;
    Node* right; Node* left;
    Node(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

class Solution{
public:
    vector<int> topView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<pair<TreeNode*,int>> q;
        map<int, int> m;
        q.push({root,0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;

            if(m.find(line)==m.end()) m[line] = node->data;

            if(node -> left != nullptr) q.push({node -> left, line-1});

            if(node -> right !=  nullptr) q.push({node ->  right, line + 1});

            for(auto it: m) {
                ans.emplace_back(it.second);
            }
        }
        return ans;
    }
};


// My Code

class Solution_1
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {   if(!root) return {};
        //Your code here
        
        map<int, Node*> m;
        vector<int> topView;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front();
            Node* tmp = temp.first;
            q.pop();
            int pos = temp.second;
            
            if(m.find(pos) == m.end()) {
                // topView.emplace_back(m[pos]);
                m[pos] = tmp;
            }
            
            if(tmp -> left) {
                q.push({tmp -> left, pos - 1});
            } 
            if(tmp -> right) {
                q.push({tmp -> right, pos + 1});
            }
        }
        
        for (auto& p : m) {
            topView.emplace_back(p.second->data);
        }
        
        return topView;
    }

};
