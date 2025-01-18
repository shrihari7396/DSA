#include <bits/stdc++.h>
using namespace std;
class Node {
public:
int data;
Node* next;
Node(int data1, Node* next1 = nullptr) {
    next = next;
    data = data1;
}
};

class Solution {
private:
    // Function to find the middle of the linked list
    Node* middle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        // Move fast pointer two steps and slow pointer one step at a time
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;  // slow pointer will be at the middle of the list
    }

    // Function to merge two sorted linked lists
    Node* merge(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);  // Create a dummy node to simplify the merge process
        Node* temp = dummy;

        // Merge nodes from list1 and list2 in sorted order
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data < list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach any remaining nodes from list1 or list2
        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        Node* ans = dummy->next;  // Get the head of the merged list
        delete dummy;  // Free the memory of the dummy node
        return ans;
    }

public:
    // Function to sort a linked list using merge sort
    Node* segregate(Node *head) {
        // Base case: if the list is empty or has only one node, it is already sorted
        if (head == nullptr || head->next == nullptr) return head;

        // Find the middle of the list
        Node* prev_middle = middle(head);
        Node* mid = prev_middle->next;
        prev_middle->next = nullptr;  // Split the list into two halves

        // Recursively sort the left and right halves
        Node* left = segregate(head);
        Node* right = segregate(mid);

        // Merge the sorted halves
        return merge(left, right);
    }
};
