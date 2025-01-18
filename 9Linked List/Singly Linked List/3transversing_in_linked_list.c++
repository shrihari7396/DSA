#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data ;
    Node* next ;
    Node(int data1 , Node* next1) {
        next = next1;
        data = data1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* arry_linked_list(vector<int>& nums){
    int n = nums.size();
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < n; i++){
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int main(void) {
    vector<int> v = {23,345,4,23,45};
    Node* head = arry_linked_list(v);
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return 0;
}
