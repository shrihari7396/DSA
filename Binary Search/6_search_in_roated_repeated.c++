#include <bits/stdc++.h>
using namespace std;

bool search_in_roated_repeating_array(vector<int> nums, int target) {
    int n = nums.size();
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
            low ++;
            high--;
            continue;
        }
        if(nums[mid] == target) {
            ans = mid;
        }
        else if(target <= nums[mid] && nums[low] <= target) {
            high = mid - 1;
        }else{
            low = mid + 1;
    }
    }
    if(ans == -1) {
        return false;
    }else {
        return true;
    }
}

int main (void) {
    vector<int> v = {2334,3434,3,323,345};
    int target = 3;
     cout <<  search_in_roated_repeating_array(v, target);
    return 0;
}