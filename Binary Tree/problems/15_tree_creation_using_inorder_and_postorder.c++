#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *right, *left;
    TreeNode(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

class Solution {
private:
    TreeNode* buildBlock(vector<int>& inorder, int inStart, int inEnd,
                         vector<int>& postorder, int postStart, int postEnd,
                         unordered_map<int, int>& inMap) {
                            if(inStart > inEnd || postStart > postEnd) return nullptr;
                            TreeNode* root = new TreeNode(postorder[postEnd]);
                            int part = inMap[postorder[postEnd]];
                            int right = inEnd - part;

                            root -> left = buildBlock(inorder, inStart, part - 1, postorder, postStart, postEnd - right - 1,inMap);
                            root -> right = buildBlock(inorder, part + 1, inEnd, postorder, postEnd - right, postEnd - 1,inMap);
                            return root;
                         }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildBlock(inorder, 0, inorder.size() - 1, postorder, 0,
                          postorder.size()-1, inMap);
    }
};

int main(void) {

    return 0;
}