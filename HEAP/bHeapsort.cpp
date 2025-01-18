#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i) {
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index
    int largest = i;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest); // Recursively heapify the affected subtree
    }
}

void buildMaxHeap(int arr[], int size) {
    // Start from the last non-leaf node and heapify each node
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heapsort(int arr[], int size) {
    buildMaxHeap(arr, size);

    // Extract elements one by one from the heap
    for (int i = size - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);     // Heapify the root
    }
}

int main() {
    int arr[] = {34, 21, 4234, 354, 23423, 52, 4, 23, 23234, 52, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int , vector<int>, greater<int>>ps;  
    heapsort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
