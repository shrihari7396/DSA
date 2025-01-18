#include <bits/stdc++.h>
using namespace std;

int search_in_rotated_array(vector<int> nums, int target) {
    int n = nums.size();
    int low = 0;int high = n - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] <= target) {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    vector<int>v = {234,1345,2334,3125,3423,3536};
    int x;
    cin >> x;
    cout << search_in_rotated_array(v,x) << endl;
    return 0;
}
