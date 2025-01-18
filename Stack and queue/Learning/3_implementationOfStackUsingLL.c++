#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};


class St{
public:
    Node* top; int size = 0;
    void push(int x) {
        Node* temp = new Node(x);
        temp -> next = temp;
        top = temp;
        size += 1;
    }

    int pop () {
        Node* to_delete = top;
        top = top -> next;
        int num = to_delete -> data;
        delete(to_delete);
        size -= 1;
        return num;
    }

    int top() {
        return top -> data;
    }

};
