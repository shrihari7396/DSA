#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int i, vector<int>& nums, int n, int sum, int target, vector<int>& dp) {
        if(i==n) return sum==target ? 1 : 0;
        
        if(dp[i]!=-1) return dp[i];

        int take = helper(i+1, nums, n, sum+nums[i], target, dp);

        int notTake = helper(i+1, nums, n, sum-nums[i], target, dp);

        return dp[i] = take+notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        vector<int> dp(n, -1);
        return helper(0, nums, n, 0, target, dp);
    }
};

int main(int argc, char** argv) {

    return 0;
}