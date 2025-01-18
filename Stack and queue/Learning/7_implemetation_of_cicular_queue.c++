#include <iostream>

class Node{
public:
    int data;
    Node *next,*prev;
    Node(int data) {
        this -> data = data;
        next = prev = nullptr;
    }
};

class MyCircularDeque {
private:
    int maxSize;
    int size;
    Node* front;
    Node* rear;
    
public:
    MyCircularDeque(int k) : maxSize(k), size(0), front(nullptr), rear(nullptr) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        Node* temp = front;
        if (front == rear) { // Single element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        Node* temp = rear;
        if (front == rear) { // Single element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }
};