class Solution {
private:
 void reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* back = nullptr;
        while(temp != nullptr) {
            ListNode* front = temp -> next;
            temp -> next = back;
            back = temp ;
            temp = front;
        }
        head = back;
    }

ListNode* kthnode(ListNode* temp, int k) {
    while(temp != nullptr && k > 0) {
        k -= 1;
        temp = temp -> next;
    }
    return temp;
}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr) {
            ListNode* kthNode = kthnode(temp, k);
            if(kthNode == nullptr) {
                if(prev) prev -> next = temp;
                break;
            }
            ListNode* nextNode = kthNode -> next;
            kthNode -> next = nullptr;
            reverse(temp);
            if(temp == head) {
                head = kthNode;
            }else{
                prev -> next = kthNode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};

class Solution {
private:
    // This function reverses the linked list from 'start' to 'end'.
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (curr != end) {
            ListNode* next = curr->next; // Store the next node
            curr->next = prev;           // Reverse the link
            prev = curr;                 // Move prev and curr one step forward
            curr = next;
        }
        return prev; // 'prev' will be the new head after the reversal
    }

    // This function finds the k-th node from the given 'start' node.
    ListNode* kthNode(ListNode* start, int k) {
        while (start != nullptr && k > 1) {
            start = start->next;
            k--;
        }
        return start;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head; // No need to reverse if k is 1 or head is null
        }

        ListNode* dummy = new ListNode(0); // A dummy node to simplify the head operations
        dummy->next = head;
        ListNode* groupPrev = dummy;
        ListNode* groupEnd = head;

        while (true) {
            // Find the k-th node from 'groupEnd'
            groupEnd = kthNode(groupPrev->next, k);
            if (groupEnd == nullptr) break; // If there's no k-th node, break the loop

            ListNode* groupStart = groupPrev->next; // Start of the group to reverse
            ListNode* nextGroupStart = groupEnd->next; // Node after the k-th node

            // Reverse the current group
            reverseList(groupStart, groupEnd->next);

            // Connect the reversed group to the previous part
            groupPrev->next = groupEnd;
            groupStart->next = nextGroupStart;

            // Move the pointers forward to the next group
            groupPrev = groupStart;
            groupEnd = groupStart;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};
