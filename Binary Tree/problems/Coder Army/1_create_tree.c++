#include <bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this -> data = data;
        right = left = nullptr;
    }
};

int main(void) {
    int x ;
    cin >> x;
    Node* root = new Node(x);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cin >> x;
        if(x != -1) {
            temp -> left =  new Node(x);
        }
    }
    return 0;
}