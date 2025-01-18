#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
    Node(): data(0), right(nullptr), left(nullptr) {}
    Node(int x) : data(x), right(nullptr), left(nullptr) {}
    Node(int x, Node*right, Node* left) : data(x), left(left), right(right) {}
};

class Solution{
public:
    int ceil_finding(Node* root, int key) {
        if(root == nullptr) return -1;
        int ceil = -1;
        while(root != nullptr) {
            if(root -> data == key) {
                ceil = root -> data;
                return ceil;
            }

            if(root -> data > key) {
                ceil = root -> data;
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
        return ceil;
    }
};
