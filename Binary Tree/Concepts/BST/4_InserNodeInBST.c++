#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

class Solution {
public:
    TreeNode* Insert(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == nullptr) return newNode;
        TreeNode* ans = root;
        while(true) {
            if(root -> val <= val) {
                if(root -> right != nullptr) {
                    root = root -> right;
                } else {
                    root -> right = newNode;
                    break;
                }
            } else {
                if(root -> left != nullptr) {
                    root = root -> left;
                } else {
                    root -> left = newNode;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(void) {

    return 0;
}