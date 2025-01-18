#include <bits/stdc++.h>
using namespace std;

class Node {
public:
int data;
Node* next;
Node(int data1, Node* next1){
    data = data1;
    next = next1;
}
Node(int data1) {
    data = data1;
}
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node* array_to_linked_list(vector<int>& nums) {
    Node* head = new Node(nums[0]);
    Node* mover = head;
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i]);
        mover -> next= temp;
        mover = temp;
    }
    return head;
}

Node* removing_head(Node* head) {
    if(head == NULL) {
        return head;
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* removing_tail(Node* head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp -> next;
    temp -> next = NULL;
    return head;
}

Node* removing_element_at_k(Node* head, int k){
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    
    Node* temp = head;
    if(temp == NULL) return head;
    Node* previous = NULL;
    int count = 0;
    while(temp != NULL){ 
        count ++;
        if(count == k){
            previous->next = previous -> next -> next;
            delete temp;
            return head;
        }
        previous = temp;
        temp = temp -> next;
    }
}

Node* removing_element_in_linked_list(Node* head, int element) {
    Node* temp = head;
    if(head == NULL) {
        return NULL;
    }

    if(head->data == element){
        head = head->next;
        delete temp;
        return head;
    }
    Node* previous = NULL;
    while(temp != NULL){
        if(temp->data == element){
            previous ->next = previous -> next -> next;
            delete temp;
            break;
        }
            previous = temp;
            temp = temp -> next;
    }
    return head;
}

int main(void) {
    vector<int> nums = {234,43,456,34,52,34,4555,34,52,3536,354,23,43,4324,534,5,23425,5,634,5,8996,356,345,35,3,56};
    Node* head = array_to_linked_list(nums);
    // Node* head1 = removing_element_at_k(head, 4);
    // print(head1);
    Node* head2 = removing_element_in_linked_list(head, 4555);
    print(head2);
    return 0;
}
