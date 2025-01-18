#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int data) {
        this -> data = data;
        left = right = nullptr;
    }
};

vector<int> preorder (TreeNode* root) {
    vector<int>ans;
    if(root == nullptr) return ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()) {
        int size = st.size();
        root = st.top();
        ans.emplace_back(root -> data);
        st.pop();
        if(root -> right != nullptr) st.push(root -> right);
        if(root -> left != nullptr) st.push(root -> left); 
    }
    return ans;
}

vector<int> inorder (TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* node = root;
    vector<int> inorder;
    while(true) {
        if(node != nullptr) {
            st.push(node);
            node = node -> left;
        }
        else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.emplace_back(node -> data);
            node = node -> right;
        }
    }
    return inorder;
}

vector<int> preorder(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    stack<int> st1;
    st.push(root);
    while(!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        st1.push(node->data);
        if(node -> left) st.push(node->left);
        if(node -> right) st.push(node->right);
    }
    while (!st1.empty())
    {
        ans.emplace_back(st.top());
        st.pop();
    }
    return ans;
}

// using two stack
vector<int> postorder (TreeNode* root) {
    vector<int> postorder;
    if(root == nullptr) {
        return postorder;
    }
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root -> left != nullptr) {
            st1.push(root->left);
        }
        if(root -> right != nullptr) {
            st1.push(root -> right);
        }
    }
    while(!st2.empty()) {
        postorder.emplace_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

int main(void) {

    return 0;
}