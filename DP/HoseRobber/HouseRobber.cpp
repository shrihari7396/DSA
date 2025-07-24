#include <bits/stdc++.h>
using namespace std;



class Solution {
    int helper(vector<int>& nums, int n, vector<int>& dp) {
        if(n >= nums.size()) return 0;

        if(dp[n]!=-1) return dp[n];
        int take = nums[n] + helper(nums, n+2, dp);
        int nonTake = helper(nums,n+1, dp);
        return dp[n]=max(take, nonTake);
    }

    int spaceOptimization(vector<int>& nums, int n) {
        vector<int> dp(n,0);
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--) {
            int take = INT_MIN;
            if(i < n-3) {
                take = nums[i] + dp[i+2];
            } 
            int notTake = dp[n+1];
            dp[n] = max(take, notTake);
        }
        return dp[0];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums, 0, dp);
    }

    
};

int main(int argc, char** argv) {

    return 0;
}