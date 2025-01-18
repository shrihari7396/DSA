#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), right(nullptr), left(nullptr) {};
};

class Solution{
    void solve(TreeNode* A, vector<vector<int>>& ans, vector<int>& temp) {
        if(!A) {
            return;
        }

        temp.emplace_back(A->val);

        if(!A->left && !A->right) {
            ans.emplace_back(temp);
        } else {
            solve(A->left, ans, temp);
            solve(A->right, ans,temp);
        }
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> rootToleaf(TreeNode* A, int B) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(A,ans, temp);
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}