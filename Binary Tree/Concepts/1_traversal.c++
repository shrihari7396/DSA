#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
    Node(int data1) {
        data = data1;
        right = nullptr;
        left = nullptr;
    }
};

void preorder (struct Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder (struct Node* root) {
    if(root == nullptr) {
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder (struct Node* root) {
    if(root == nullptr) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";

}

int main(void) {

    return 0;
}