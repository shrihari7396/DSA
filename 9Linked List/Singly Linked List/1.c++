#include <iostream>
using namespace std;
struct  shrihari
{
    int data;
    int* next;
    shrihari(int data1, int* next1){
        data = data1;
        next = next1;
    }
};


class Node {
public:
int data;
Node* next;
Node(int x, Node* y) {
    data = x;
    next = y;
}
};

int main()
{
    Node* x = new Node(23,nullptr); // it gives us the memory location

    // for acesing data from the above we uses dereference operator
    cout << x -> data << endl;
    cout << x -> next;
    /*Node x = Node (23,nullptr);  // it creates an object of the above class Node*/
    cout << x << endl;
    return 0;
}