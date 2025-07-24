#include <bits/stdc++.h>
using namespace std;

int helper(int target, int i, vector<int>& nums, map<pair<int, int>, bool>& dp) {
    if(target == 0) {
        return dp[{i, target}] = 1;
    }

    if(i == 0) return target == nums[0];

    if(dp.find({i, target})!=dp.end()) {
        return dp[{i, target}];
    }

    int notTake = helper(target, i-1, nums, dp);

    int take = false;
    if(target >= nums[i]) {
        take = helper(target-nums[i], i-1, nums, dp);
    }

    return notTake + take;
}

// When their is zero in the array
int helperWithZeros(int i, int target, vector<int>& nums) {
    if(i==0) {
        if(target==0 && nums[0] == 0) return 2;
        if(target == 0 || nums[0]==target) return 1;
        return 0;
    }

    int notTake = helperWithZeros(i-1, target, nums);
    int take = 0;

    if(target >= nums[i]) {
        take = helperWithZeros(i-1, target-nums[i], nums);
    }

    return take + notTake;
}



int main(int argc, char** argv) {

    return 0;
}