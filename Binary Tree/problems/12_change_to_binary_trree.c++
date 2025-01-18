#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* right, *left;
    TreeNode(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

class Solution {
    public:
    void changeToChileProperty(TreeNode* root) {
        if(root == nullptr) return ;
        int child = 0;
        if(root -> left) {
            child += root -> left -> data;
        }
        if(root -> right) {
            child += root -> right -> data;
        }

        if(child >= root -> data) {
            root -> data = child;
        } else {
            if(root -> left) {
                root -> left -> data = root -> data;
            } else if(root -> right) {
                root -> right -> data = root -> data;
            }
        }

        changeToChileProperty(root -> left);
        changeToChileProperty(root -> right);

        int tot = 0;
        if(root -> left) tot += root -> left -> data;
        if(root -> right) tot += root -> right -> data;
        if(root -> left || root -> right) root -> data = tot;
    }
};

int main(void) 
{

    return 0;
}