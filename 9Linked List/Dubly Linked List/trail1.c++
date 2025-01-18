
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // Start fast one step ahead to find the previous middle node
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge_linked_list(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        ListNode* ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* midPrev = middle(head); // Previous node to the middle to split the list
        ListNode* mid = midPrev->next;    // Actual middle node
        midPrev->next = nullptr;          // Split the list into two halves

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge_linked_list(left, right);
    }
};
