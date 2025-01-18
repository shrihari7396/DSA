#include <bits/stdc++.h>
using namespace std;

class Node {
public:
int data;
Node* next;
Node* prev;


Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
    data = data1;
    next = next1;
    prev = prev1;
}

};


Node* array_to_Singly_LL(vector<int>& nums) {
    Node* head = new Node(nums[0]);
    Node* mover = head;
    int n = nums.size(); 
    for(int i = 1;  i < n; i++) {
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

Node* array_to_Doubly_LL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    int n = nums.size();
    Node* prev = head;
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i],nullptr,prev);
        prev -> next = temp ;   
        prev = temp;
    } 
}

void print_linked_list(Node* head) {
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
}

int main(void) {
    vector<int> nums = {23,34,54,657,87,565,567,7898};
    Node* head = array_to_Singly_LL(nums);
    print_linked_list(head);
    return 0;
}
