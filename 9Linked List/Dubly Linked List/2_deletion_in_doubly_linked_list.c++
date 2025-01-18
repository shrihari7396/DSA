#include <bits/stdc++.h>
using namespace std;

class Node {
public:
int data;
Node* next;
Node* prev;
Node(int data1, Node* next1 = nullptr,Node* pre1 = nullptr) {
    data = data1;
    next = next1;
    prev = pre1;
}
};

void print_LL(Node* head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* array_to_doubly_LL (vector<int>& nums)
 {
    Node* head = new Node(nums[0]);
    Node* prev = head;
    int n = nums.size();
    for(int i = 1; i < n; i++){
        Node* temp = new Node(nums[i],nullptr,prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

Node* deletion_of_head_in_doubly_LL(Node* head) {
    if(head == nullptr ){
        return NULL;
    }
    if(head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    head = head -> next;
    head -> prev = nullptr;
    delete temp;
    return head;
}

Node* deletion_of_tail_in_doubly_linked_list(Node* head) {
    if(head == nullptr){
        return nullptr;
    }
    if(head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* tail = head;
    while (tail -> next != nullptr){
        tail = tail -> next;
    }
    tail -> prev -> next = nullptr;
    delete tail;
    return head;
}

Node* deletion_of_element_at_k_th_position(Node* head, int k) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count <= k)
    {
        count ++;
        if (count == k)
        {
            break;
        }
        temp = temp -> next;
    }
    Node* back = temp -> prev;
    Node* front = temp -> next;
    if(back == nullptr && front == nullptr){
        delete temp;
        return nullptr;
    }
    else if(back == nullptr) {
        return deletion_of_head_in_doubly_LL( head);
        
    }else if(front == nullptr){
        return deletion_of_tail_in_doubly_linked_list(head);
    }
    front -> prev = back;
    back -> next = front;
    front = nullptr;
    back = nullptr;
    delete temp;
    return head;
}

void delete_node(Node* node) {
    Node* back = node -> prev;
    Node* front = node -> next;
    if(front == nullptr) {
        back -> next = nullptr;
        back = nullptr;
        return;
    }
    back -> next = node -> next;
    front -> prev = node -> prev;
    node -> prev = nullptr;
    node -> next = nullptr;
    delete node;
}

int main(void) {
    vector<int> nums = {234,4353,634,2414,534,23};
    Node* head = array_to_doubly_LL(nums);

    // Node* head1 = deletion_of_head_in_doubly_LL(head);    
    // print_LL(head1);
    // cout << endl;
    // Node* head2 = deletion_of_tail_in_doubly_linked_list(head1);
    // print_LL(head2);
    // cout << endl;
    // Node* head3 = deletion_of_element_at_k_th_position(head, 3);
    // print_LL(head3);
    // cout << endl;
    delete_node(head->next->next);
    print_LL(head);
    return 0;
}
