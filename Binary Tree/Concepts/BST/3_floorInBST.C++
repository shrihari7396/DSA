#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *right, Node *left) : data(x), left(left), right(right) {}
};

class Solution {
public: 
    int floor(Node* root, int x) {
        // Code here
        if(root == nullptr) return -1;
        int floor1 = -1;
        while(root) {
            if(root -> data == x) {
                floor1 = root -> data;
                return floor1;
            }
            if(root -> data > x) {
                root = root -> left;
            } else {
                floor1 = root -> data;
                root = root -> right;
            }
        }
        return floor1;
    }
};

int main(void) {

    return 0;
}
