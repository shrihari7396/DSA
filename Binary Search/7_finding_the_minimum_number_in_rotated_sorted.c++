#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int ans = INT_MAX;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[low] <= nums[mid]) {
            ans = min(ans,nums[low]);
            low = mid + 1;
        }else {
            ans = min(ans,nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    vector<int> v = {34,45,56,78,1,2,3,4,5};
    cout << search(v) << endl;
    return 0;
}