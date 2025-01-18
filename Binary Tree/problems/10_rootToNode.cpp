#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data), right(nullptr), left(nullptr) {};
};

class Solution{
    bool getPath(TreeNode* root, vector<int>& ans, int x) {
        if(!root) return false;
        ans.emplace_back(root->data);
        if(root->data == x) return true;

        if(getPath(root -> left, ans, x) || getPath(root -> right, ans, x)) {
            return true;
        }
        ans.pop_back();
        return false;
    }
public:
    vector<int> solve(TreeNode* A, int B) {
        vector<int> ans;
        if(!A) return ans;
        getPath(A, ans, B);
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}