#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& nums) {
    int size = nums.size();
    for(int gap = size/2; gap > 0; gap /= 2) {
        for(int i = gap; i < size; i++) {
            int temp = nums[i];
            int j ;
            for(j = i; j >= gap && nums[j-gap] > temp; j -= gap) {
                nums[j] = nums[j-gap];
            }
            nums[j] = temp;
        }
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {8, 5, 3, 7, 2, 4, 6, 1};
    
    cout << "Original array: ";
    printArray(arr);
    
    shellSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}