#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool exists(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

Node* intersection(Node* setA, Node* setB) {
    Node* result = nullptr;
    Node* temp = setA;
    while (temp != nullptr) {
        if (exists(setB, temp->data)) {
            insert(result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

Node* symmetricDifference(Node* setA, Node* setB) {
    Node* result = nullptr;
    Node* temp = setA;
    while (temp != nullptr) {
        if (!exists(setB, temp->data)) {
            insert(result, temp->data);
        }
        temp = temp->next;
    }
    temp = setB;
    while (temp != nullptr) {
        if (!exists(setA, temp->data)) {
            insert(result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

int countNeither(Node* setA, Node* setB, int totalStudents) {
    Node* unionSet = nullptr;
    Node* temp = setA;
    // Add all elements from set A to union set
    while (temp != nullptr) {
        if (!exists(unionSet, temp->data)) {
            insert(unionSet, temp->data);
        }
        temp = temp->next;
    }
    temp = setB;
    // Add all elements from set B to union set
    while (temp != nullptr) {
        if (!exists(unionSet, temp->data)) {
            insert(unionSet, temp->data);
        }
        temp = temp->next;
    }
    
    // Count how many are in union
    int unionCount = 0;
    temp = unionSet;
    while (temp != nullptr) {
        unionCount++;
        temp = temp->next;
    }
    
    // Students who like neither will be total students minus union count
    return totalStudents - unionCount;
}

int main() {
    Node* setA = nullptr;
    Node* setB = nullptr;
    
    int totalStudents = 10;  // Total number of students
    int vanilla[] = {1, 2, 3, 4};  // Students who like Vanilla
    int butterscotch[] = {3, 4, 5, 6};  // Students who like Butterscotch
    
    // Insert vanilla students into setA
    for (int i = 0; i < 4; i++) {
        insert(setA, vanilla[i]);
    }
    
    // Insert butterscotch students into setB
    for (int i = 0; i < 4; i++) {
        insert(setB, butterscotch[i]);
    }
    
    cout << "Set A (Vanilla): ";
    display(setA);
    
    cout << "Set B (Butterscotch): ";
    display(setB);
    
    // (a) Students who like both vanilla and butterscotch
    Node* both = intersection(setA, setB);
    cout << "\n(a) Students who like both Vanilla and Butterscotch: ";
    display(both);
    
    // (b) Students who like either vanilla or butterscotch but not both
    Node* eitherButNotBoth = symmetricDifference(setA, setB);
    cout << "\n(b) Students who like either Vanilla or Butterscotch but not both: ";
    display(eitherButNotBoth);
    
    // (c) Number of students who like neither vanilla nor butterscotch
    int neither = countNeither(setA, setB, totalStudents);
    cout << "\n(c) Number of students who like neither Vanilla nor Butterscotch: " << neither << endl;
    
    return 0;
}
