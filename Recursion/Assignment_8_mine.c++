/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream
and set B of students like butterscotch ice-cream. Write C++ program to store two
sets using linked list. compute and display-
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this -> data = data;
    }
};

Node* vec_to_ll(vector<int>& nums) {
    Node* head = new Node(nums[0]);
    int size = nums.size();
    Node* mover = head;
    for(int i = 0; i < size; i++) {
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head) {
    if(head == nullptr) return;
    while(head != nullptr) {
        cout << head -> data << " ";
        head = head -> next;
    }
    return;
}

int main(void) {
    cout << "Enter Total Students seprated by spaces: " << endl;
    cout << "Enter Number of Students like vanilla icecream: " ;
    int v ;
    cin >> v;
    vector<int> va;
    cout << "Note: input must in format '123 456 324 5345 323'. "  << endl;
    for(int i = 0; i < v; i++) {
        int temp;
        cin >> temp;
        va.emplace_back(temp);
    }
    Node* van = vec_to_ll(va);

    cout << "Enter Number of Students like ButterScotch icecream: ";
    int b;
    cin >> b;
    vector<int> bu;
    cout << "Note: input must in format '123 456 324 5345 323'. "  << endl;
    for(int i = 0; i < v; i++) {
        int temp;
        cin >> temp;
        bu.emplace_back(temp);
    }
    Node* but = vec_to_ll(bu);

    vector<int> van_but; // Storage ara

    unordered_map<int, int> m;

    Node* temp1 = van;

    while(temp1 != nullptr) {
        m[temp1 -> data] = 0;
        temp1 = temp1 -> next;
    }
    temp1 = van;
    Node* temp2 = but;

    while(temp2 != nullptr) {
        if(m.find(temp2 -> data) != m.end()) {
            van_but.emplace_back(temp2 -> data);
        }
        temp2 = temp2 -> next;
    }

    Node* both = vec_to_ll(van_but);

    cout << "Set of students who like both vanilla and butterscotch : " << endl;
    print(both);

    unordered_map<int, int> m1;
    temp2 = but;
    while(temp2 != nullptr) {
        m1[temp2 -> data] = 0;
        temp2 = temp2 -> next;
    }

    // but and van

    vector<int> van_or_but_not_both;

    while(temp2 != nullptr) {
        if(m.find(temp2 -> data) == m.end()) {
            van_or_but_not_both.emplace_back(temp2 -> data);
        }
        temp2 = temp2 -> next;
    }

    return 0;
}


class Solution {
public:
    #include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to create a linked list from a vector
Node* vec_to_ll(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < nums.size(); i++) {
        mover->next = new Node(nums[i]);
        mover = mover->next;
    }
    return head;
}

// Function to print a linked list
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to get the set of unique values from a linked list
unordered_set<int> ll_to_set(Node* head) {
    unordered_set<int> s;
    while (head != nullptr) {
        s.insert(head->data);
        head = head->next;
    }
    return s;
}

int main() {
    cout << "Enter Total Number of Students: ";
    int total_students;
    cin >> total_students;
    
    // Input for Vanilla set
    cout << "Enter Number of Students who like Vanilla Ice-cream: ";
    int v;
    cin >> v;
    vector<int> vanilla;
    cout << "Enter the Roll Numbers of Students who like Vanilla: ";
    for (int i = 0; i < v; i++) {
        int temp;
        cin >> temp;
        vanilla.push_back(temp);
    }
    Node* vanilla_ll = vec_to_ll(vanilla);

    // Input for Butterscotch set
    cout << "Enter Number of Students who like Butterscotch Ice-cream: ";
    int b;
    cin >> b;
    vector<int> butterscotch;
    cout << "Enter the Roll Numbers of Students who like Butterscotch: ";
    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        butterscotch.push_back(temp);
    }
    Node* butterscotch_ll = vec_to_ll(butterscotch);

    // Convert linked lists to sets
    unordered_set<int> vanilla_set = ll_to_set(vanilla_ll);
    unordered_set<int> butterscotch_set = ll_to_set(butterscotch_ll);

    // a) Set of students who like both vanilla and butterscotch (Intersection)
    vector<int> both;
    for (int roll : vanilla_set) {
        if (butterscotch_set.find(roll) != butterscotch_set.end()) {
            both.push_back(roll);
        }
    }
    cout << "Set of students who like both vanilla and butterscotch: ";
    for (int roll : both) {
        cout << roll << " ";
    }
    cout << endl;

    // b) Set of students who like either vanilla or butterscotch but not both (Symmetric Difference)
    vector<int> either_not_both;
    for (int roll : vanilla_set) {
        if (butterscotch_set.find(roll) == butterscotch_set.end()) {
            either_not_both.push_back(roll);
        }
    }
    for (int roll : butterscotch_set) {
        if (vanilla_set.find(roll) == vanilla_set.end()) {
            either_not_both.push_back(roll);
        }
    }
    cout << "Set of students who like either vanilla or butterscotch but not both: ";
    for (int roll : either_not_both) {
        cout << roll << " ";
    }
    cout << endl;

    // c) Number of students who like neither vanilla nor butterscotch
    int neither_count = 0;
    for (int i = 1; i <= total_students; i++) {
        if (vanilla_set.find(i) == vanilla_set.end() && butterscotch_set.find(i) == butterscotch_set.end()) {
            neither_count++;
        }
    }
    cout << "Number of students who like neither vanilla nor butterscotch: " << neither_count << endl;

    return 0;
}

};