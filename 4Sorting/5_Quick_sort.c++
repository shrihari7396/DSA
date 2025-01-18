#include <bits/stdc++.h>
using namespace std;

int getting_pivot(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i < high){
            i ++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
        swap(arr[low],arr[j]);
        return j;
}

void quick_sort(int arr[] , int low , int high){
    if(low < high){
        int pivot = getting_pivot(arr, low, high);
        quick_sort(arr,low,pivot - 1);
        quick_sort(arr,pivot + 1, high);
    }
}

int main(void){
    int arr[] = {434,34,234,345,345};
    int low = 0;
    int high = 4;
    quick_sort(arr, low, high);
    for(int i = 0; i < 5;  i++){
        cout << arr[i] << " ";
    }
    return 0;
}
