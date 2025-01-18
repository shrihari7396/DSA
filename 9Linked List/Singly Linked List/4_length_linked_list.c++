#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data ;
    Node* next;
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* array_to_LL(vector<int>& nums){
    Node* head = new Node (nums[0]);
    int n = nums.size();
    Node* mover = head;
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count ++;
        temp = temp -> next;
    }
    return count;
}
int main(void) {
    vector <int> nums = {34,324,345,234,45355,4};
    Node* head = array_to_LL(nums);
    cout << "Length of the linked list is: " << length(head) << endl; 
    return 0;
}
