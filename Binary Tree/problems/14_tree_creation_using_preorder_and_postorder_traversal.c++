// #include <bits/stdc++.h>
// using namespace std;

// class TreeNode{
// public:
//     int data;
//     TreeNode *left, *right;
//     TreeNode(int data) {
//         this -> data = data;
//         left = right = nullptr;
//     }
// };

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         map<int, int> inMap;
//         for(int i = 0; i < inorder.size(); i++) {
//             inMap(inorder[i]) = i;
//         }  
        
//         TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()), map<int,int>& inMap;
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, int prestart, int preEnd, vector<int>& inorder, int inStart, int inEnd) [
//         if(preStart > preEnd || inStart > inEnd) {
//             return nullptr;
//         }

//         TreeNode* root = new TreeNode(perorder[preStart]);

//         int inRoot = inMap
//     ]
// };  

// int main(void) {

//     return 0;
// }

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

class Solution {
private:
    TreeNode* buildBlock(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {
        if(preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int part = inMap[preorder[preStart]];
        int leftTreeSize = part - inStart;

        root -> left = buildBlock(preorder, preStart+1, preStart+leftTreeSize, inorder, inStart, part-1, inMap);
        root -> right = buildBlock(preorder, preStart+leftTreeSize+1, preEnd, inorder, part + 1, inEnd, inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for(int i = 0; i < preorder.size(); i++) {
            inMap[preorder[i]] = i;
        }

        return buildBlock(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inMap);
    }
};

int main(void) {

    return 0;
}