#include <bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;
Node* prev;
Node(int data1, Node* next1 = nullptr, Node* prev1 =nullptr){
    data = data1;
    next = next1;
    prev = prev1;
}
};

void print_LL(Node* head) {
    while(head != nullptr) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* array_to_LL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i], nullptr,prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

Node* insertion_at_head(Node* head,int k) {
    if(head == nullptr) {
        return new Node(k);
    }
    Node* newnode = new Node(k,head,nullptr);
    head -> prev = newnode;
    return newnode;
}

Node* insertion_at_tail(Node* head, int k){
    if(head == nullptr) {
        return new Node(k);
    }
    Node* newnode = new Node(k);
    Node* temp = head;
    while(temp -> next == nullptr) {
        temp = temp -> next;
    }
    newnode -> prev = temp;
    temp -> next = newnode;
    return head;
}

Node* insertion_before_tail_of_LL(Node* head, int k) {
    if(head == NULL) {
        return new Node(k);
    }
    Node* temp = head;
    while(temp -> next != nullptr) {
        temp = temp -> next;
    }
    Node* newnode = new Node(k);
    if(temp -> prev == nullptr) {

        newnode -> next = temp;
        temp -> prev = newnode;
        newnode -> prev = nullptr;
        return newnode;
    }
    newnode -> next = temp;
    newnode -> prev = temp -> prev;
    temp -> prev -> next = newnode;
    temp -> prev = newnode;
    return head;
}

Node* insert_before_kth_element_in_LL(Node* head, int k, int val) {
    if(k == 1) {
        return insertion_at_head(head, k); 
    }
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count ++   ;
        if(count == k) {
            break;
        }
        temp = temp -> next;
    }
    Node* back = temp -> prev;
    Node* newnode = new Node(val,temp,back);
    back -> next = newnode;
    temp -> prev = newnode;
    return head;
}

void insertbeforenode(Node* node, int val)  {
    Node* back = node -> prev;
    Node* newnode = new Node(val,node,back);
    back-> next = newnode;
    node -> prev = newnode;
}

int main(void) {
    vector <int> v = {234,456,678,34,5656,89,5,634,4};
    Node* head = array_to_LL(v);
    Node* head2 = insert_before_kth_element_in_LL(head,  4, 99999090);
    print_LL(head2);
    return 0;
}