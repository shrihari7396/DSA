#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;  // Start with index 1 for convenience
        size = 0;
    }

    void insert(int data) {
        size++;
        int index = size;
        arr[index] = data;

        // Bubble up to maintain the max heap property
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                return;  // Heap property is satisfied
            }
        }
    }

    void Delete() {
        if (size == 0) {
            cout << "Nothing to delete here!" << endl;
            return;
        }

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Heapify to maintain heap property
        int i = 1;
        while (i < size) {
            int left = i * 2;
            int right = i * 2 + 1;
            int largest = i;

            // Compare with left child
            if (left <= size && arr[left] > arr[largest]) {
                largest = left;
            }

            // Compare with right child
            if (right <= size && arr[right] > arr[largest]) {
                largest = right;
            }

            // If current node is larger than both children, heap property is satisfied
            if (largest == i) {
                return;
            }

            // Swap with the largest of the children
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


// This for the maxheap
void hepify(int arr[], int n, int i) {
        int right=i*2+1;
        int left=i*2;
        int largest=i;

        if(left<n && arr[largest] < arr[left]) {
            i=left;
        }   
        
        if(right<n && arr[largest] < arr[right]) {
            i=right;
        }

        if(i!=largest) {
            swap(arr[i], arr[largest]);
            hepify(arr, n, largest);
        }
        
}

//This is for the minheap
void hepify(int arr[], int n, int i) {
        int right=i*2+2;
        int left=i*2+1;
        int smallest=i;

        if(left<n && arr[smallest] < arr[left]) {
            i=left;
        }   
        
        if(right<n && arr[smallest] < arr[right]) {
            i=right;
        }

        if(i!=smallest) {
            swap(arr[i], arr[smallest]);
            hepify(arr, n, smallest);
        }       
}

int main() {
    Heap h2;
    h2.insert(50);
    h2.insert(55);
    h2.insert(53);
    h2.insert(52);
    h2.insert(54);
    h2.print();  // Expected: 55 54 53 50 52

    h2.Delete();
    h2.print();  // Expected: 54 52 53 50
    int n=5;
    int arr[6] = {-1,54,53,55,52,50};
    for(int i =n/2; i>0;i--) {
        hepify(arr, n, i);
    }
    for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    return 0;
}
