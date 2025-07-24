#include <bits/stdc++.h> 
using namespace std;

// Memoisation
bool helper(int target, int i, vector<int>& nums, map<pair<int, int>, bool>& dp) {
    if(target == 0) {
        return dp[{i, target}] = true;
    }

    if(i == 0) return target == nums[0];

    if(dp.find({i, target})!=dp.end()) {
        return dp[{i, target}];
    }

    bool notTake = helper(target, i-1, nums, dp);

    bool take = false;
    if(target >= nums[i]) {
        take = helper(target-nums[i], i-1, nums, dp);
    }
    return dp[{i, target}] = take || notTake;
}

// Tabulation
bool helper(int k, int n, vector<int>& nums) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0;i<n;i++) {
        dp[i][0] = true;
    }

    dp[0][nums[0]] = true;

    for(int ind=1;ind<n;ind++) {
        for(int target=0;target<=k;target++) {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(nums[ind] <= target) {
                take = dp[ind-1][target-nums[ind]];
            }
            dp[ind][target] = take || notTake;
        }
    }

    return dp[n-1][k];
}

//Space Optimisation
bool helper(int k, int n, vector<int>& nums) {

    vector<bool> prev(k+1,false);
    prev[0] = true;
    if(nums[0] <= k) prev[nums[0]] = true;
 
    for(int ind=1;ind<n;ind++) {
        vector<bool> curr(k+1,false);
        curr[0] = true;
        for(int target=0;target<=k;target++) {
            bool notTake = prev[target];
            bool take = false;
            if(nums[ind] <= target) {
                take = prev[target-nums[ind]];
            }
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    map<pair<int,int>, bool> dp;
    int hash = 0;
    return helper(k, n-1, arr, dp);
}

int main(int argc, char** argv) {
    
    return 0;
}