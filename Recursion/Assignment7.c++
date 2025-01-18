#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* array_to_DLL(const vector<int>& nums) {
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        Node* temp = new Node(nums[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* reverse_DLL(Node* head) {
    if (!head) return nullptr;
    Node* temp = nullptr;
    Node* current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    return temp ? temp->prev : head;
}

void print_DLL(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
}

Node* one_s_complement(Node* head) {
    Node* temp = head;
    while (temp) {
        temp->data = (temp->data == 0) ? 1 : 0;
        temp = temp->next;
    }
    return head;
}

Node* add_binary(Node* num1, Node* num2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 2;
        sum = sum % 2;

        Node* newNode = new Node(sum);
        if (!result) {
            result = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }
    return result;
}

Node* two_s_complement(Node* head) {
    Node* onesComp = one_s_complement(head);
    Node* reversed = reverse_DLL(onesComp);
    Node* one = new Node(1);
    Node* result = add_binary(reversed, one);
    delete one;
    return reverse_DLL(result);
}

void delete_DLL(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

string convert_int_to_str(int num) {
    if (num == 0) return "0";
    string binaryStr;
    while (num) {
        binaryStr += (num % 2 == 0) ? '0' : '1';
        num /= 2;
    }
    reverse(binaryStr.begin(), binaryStr.end());
    return binaryStr;
}

int main() {
    cout << "Note: Enter data in the format of Integer :" << endl;
    cout << "===================================================" << endl;

    int a, b;
    cout << "Enter First number: ";
    cin >> a;
    cout << "Enter Second number: ";
    cin >> b;

    string s1 = convert_int_to_str(a);
    string s2 = convert_int_to_str(b);

    cout << "Binary representation of first number: " << s1 << endl;
    cout << "Binary representation of second number: " << s2 << endl;

    vector<int> N1(s1.size());
    vector<int> N2(s2.size());

    for (size_t i = 0; i < s1.size(); ++i) N1[i] = s1[i] - '0';
    for (size_t i = 0; i < s2.size(); ++i) N2[i] = s2[i] - '0';

    Node* link1 = array_to_DLL(N1);
    Node* link2 = array_to_DLL(N2);

    cout << "====================================================" << endl;

    Node* ones_complement_1 = one_s_complement(link1);
    cout << "One's complement of the first number is: ";
    print_DLL(ones_complement_1);
    cout << endl;
    delete_DLL(ones_complement_1);

    Node* ones_complement_2 = one_s_complement(link2);
    cout << "One's complement of the second number is: ";
    print_DLL(ones_complement_2);
    cout << endl;
    delete_DLL(ones_complement_2);

    link1 = array_to_DLL(N1);
    link2 = array_to_DLL(N2);

    Node* twos_complement_1 = two_s_complement(link1);
    cout << "Two's complement of the first number is: ";
    print_DLL(twos_complement_1);
    cout << endl;
    delete_DLL(twos_complement_1);

    Node* twos_complement_2 = two_s_complement(link2);
    cout << "Two's complement of the second number is: ";
    print_DLL(twos_complement_2);
    cout << endl;
    delete_DLL(twos_complement_2);

    cout << "====================================================" << endl;

    delete_DLL(link1);
    delete_DLL(link2);

    return 0;
}
