#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool ispossible(vector<int>& nums, int days, int mid){
        int n = nums.size();
        int count = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(count > days) {
                return false;
            }
            if(sum + nums[i] > mid){
                sum = nums[i];
                count++;
                if(nums[i] > mid){
                    return false;
                }
            }else{
                sum += nums[i];
            }
        }
        return true;
    }

    int answer(vector<int>& nums, int days) {
        int n = nums.size();
        int low = 0;
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high-low)/2;
            if(ispossible(nums,days,mid)) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};

// leetcode
class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();
        int low =  0;
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (days_required(nums, mid, days)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool days_required(vector<int>& nums, int capacity, int days) {
        int n = nums.size();
        int sum = 0;
        int days1 = 1;
        for (int i = 0; i < n; i++) {
            if(nums[i] > capacity) {
                return false;
            }
            if (sum + nums[i] > capacity) {
                days1 += 1;
                sum = nums[i];
                if(days1 > days){
                    return false;
                }
            } else {
                sum += nums[i];
            }
        }
        return true;
    }
};

