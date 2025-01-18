#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int data) {
        this -> data = data;
        right = nullptr;
        left = nullptr;
    }
};
class Solution {
public:
    int height_of_tree(Node* root) {
        if(root == nullptr) {
            return 0;
        }
        int l = height_of_tree(root -> left);
        int r = height_of_tree(root -> right);
        return max(l,r)+1;
    }
};