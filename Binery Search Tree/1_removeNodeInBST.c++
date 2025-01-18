
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    TreeNode* findRightestNode(TreeNode* root) {
        if (!root->right) {
            return root;
        }
        return findRightestNode(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr)
            return root->right;
        if (root->right == nullptr)
            return root->left;

        TreeNode* lastRightNode = findRightestNode(root->left);
        lastRightNode->right = root->right;

        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        TreeNode* parent = nullptr;  
        
        while (root) {
            if (root->val == key) {
                if (parent->left == root) {
                    parent->left = helper(root);
                } else {
                    parent->right = helper(root);
                }
                break;
            } else if (root->val > key) {
                parent = root;
                root = root->left;
            } else {
                parent = root;
                root = root->right;
            }
        }
        return dummy;
    }
};
