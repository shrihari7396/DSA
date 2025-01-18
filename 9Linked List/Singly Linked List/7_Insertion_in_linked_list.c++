#include <bits/stdc++.h>
using namespace std;

class Node {
public:

int data;
Node* next;
Node(int data1, Node* next1 = nullptr) {
    data = data1;
    next = next1;
}
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

Node* array_to_LL(vector<int>& nums) {
    int n = nums.size();
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* Insertion_in_linked_list_at_head(Node* head) {
    Node* temp = new Node(234, head);
    return temp;
}

Node* Insertion_in_linked_list_at_tail(Node* head) {
    Node* last = new Node(234);
    Node* temp = head;
    if(head == NULL) {
        return last;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = last;
    return head;
}

Node* Insertion_at_k_th_position_in_linked_list(Node* head,int x,int k) {
    Node* insertion_node = new Node(x);
    if(head == NULL) {
        return NULL;    
    }
    if(k == 1) {
        insertion_node->next = head;
        return insertion_node;
        }
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count ++;
        if(count == k-1){
            insertion_node -> next = temp->next;
            temp -> next = insertion_node;
            return head;
        }
        temp = temp -> next;
    }
}

Node* insert_the_value(Node* head,int el, int val){
    if(head == NULL) {
        return head;
    }
    if(head -> data == val) {
        return new Node(el, head);
    }
    
    Node* temp = head;
    while(temp -> next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp= temp->next;
    }
    return head;
}

int main(void)  {
    vector<int> nums = {324,2353,523,42324,25,23,34};
    Node* head = array_to_LL(nums);
    head =  Insertion_at_k_th_position_in_linked_list(head,10000,4);
    print(head);
    return 0;
}
