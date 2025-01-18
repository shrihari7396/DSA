#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left ++;
        }
        else {
            temp.push_back(arr[right]);
            right ++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left ++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right ++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void merge_sorting(int arr[], int low, int high){
    if(low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    merge_sorting(arr, low, mid);
    merge_sorting(arr, mid + 1, high);
    merge(arr, low, mid, high);

}
int main(void){
    int N;
    cout << "Enter size of the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter elements of the array: " << endl;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = N - 1;

    merge_sorting(arr, low, high);

    cout << "Sorted array: ";
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}