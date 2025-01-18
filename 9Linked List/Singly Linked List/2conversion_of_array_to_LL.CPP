#include <bits/stdc++.h>
using namespace std;
// Conversion of the array to the Linked List
class Node{
    public:
    int data;
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

Node* Convert_array_to_Linked_list(vector<int> &arr){
    Node* head = new Node(arr[0]); // as head stores the memory location
    Node* mover = head; // initially mover stores the location of the first element in the array
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]); // arr[i] is an interger hence it is stored in the data (member of object head)
        mover->next = temp;
        mover = temp; 
    }
    return head;
}

int main()
{   vector<int>v = {32,341,23,2343,23};
    Node* head = Convert_array_to_Linked_list(v);
    // cout << head -> data;
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return 0;
}
