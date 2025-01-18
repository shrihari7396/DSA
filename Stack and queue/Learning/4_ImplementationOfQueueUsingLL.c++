#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Qu {
public:
    Node *start = nullptr, *end = nullptr;
    int sz = 0;  // Renamed to avoid conflict with the method name
    
    void push(int x) {
        Node* temp = new Node(x);
        if (start == nullptr) {
            start = end = temp;  // Initialize both start and end
        } else {
            end->next = temp;    // Link the new node to the end
            end = temp;          // Update the end pointer
        }
        sz++;  // Increment size
    }

    int pop() {
        if (start == nullptr) return -1;  // Queue is empty
        int num = start->data;            // Get the data from the front
        Node* Dummy = start;              // Temporary pointer to delete the old front
        start = start->next;              // Move start to the next node
        delete Dummy;                     // Free the memory
        sz--;                             // Decrement size
        return num;                       // Return the popped value
    }

    int getSize() {                     // Renamed method to avoid conflict
        return sz;
    }

    int top() {
        if (start == nullptr) return -1; // Queue is empty
        return start->data;              // Return the front value
    }
};
