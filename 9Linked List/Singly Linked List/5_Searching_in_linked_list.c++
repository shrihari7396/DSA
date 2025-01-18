#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1)  {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* vector_LL(vector<int>& nums) {
    int n = nums.size();
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

bool searching_in_LL(Node* head, int key){
    Node* temp = head;
    while(temp) {
        if(temp -> data == key){
            return true;
        }
    temp = temp->next;
    }
}

int main(void) {

    vector<int> nums = {34,345,345,323,324};
    Node* head = vector_LL(nums);
    int key;
    cout << "Enter Key: " ;
    cin >> key;
    if(searching_in_LL(head,key)) {
        cout << "Yes element is present" << endl;
     }else{
        cout << "Elemtent is not present" << endl;
     }

    return 0;
}
