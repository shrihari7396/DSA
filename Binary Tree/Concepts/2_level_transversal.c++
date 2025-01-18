#include <bits/stdc++.h>
using namespace std ;

class root {
public:
    int data;
    root* right;
    root* left;
    root(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

vector<vector<int>> level_traversal(root* tree) {
    vector<vector<int>> ans;
    if(tree == nullptr) return ans;
    queue<root*>q;
    q.push(tree);
    while(!q.empty()) {
        vector<int> level;
        int size = q.size();
        for(int i = 0; i < size; i++) {
            root* tree = q.front();
            q.pop();
            if(tree -> left != nullptr) {
                q.push(tree -> left);
            }
            if(tree -> right != nullptr) {
                q.push(tree -> right);
            }
            level.emplace_back(tree->data);
        }
        ans.emplace_back(level);
    }
    return ans;
}
// Time complexity of the algorithm is O(N) and worst case space time complexity is O(N)
int main(void) {

    return 0;
}