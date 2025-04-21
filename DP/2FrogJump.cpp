#include <bits/stdc++.h>
using namespace std;
// Memoizations
class Solution {
    private:
      int solve(int n, vector<int>& nums, vector<int>& dp) {
          if(n==0) return 0;
          int right=INT_MAX;
          if(dp[n]!=-1) {
              return dp[n];
          }
          int left = solve(n-1, nums, dp) + abs(nums[n] - nums[n-1]);
          if(n>1) {
              right = solve(n-2, nums, dp) + abs(nums[n] - nums[n-2]);
          }
          
          return dp[n] = min(left, right);
      }
    public:
      int minCost(vector<int>& height) {
          // Code here
          vector<int> dp(height.size()+1, -1);
          int minCost = INT_MIN;
          
          return solve(height.size()-1, height, dp);
      }
  };

// Tabulation

int minCost(vector<int>& height) {
    // Code here
    vector<int> dp (height.size(),0);
    int n=height.size();
    
    for(int i=1;i<height.size();i++) {
        int first = dp[i-1]+abs(height[i]-height[i-1]);
        int second = INT_MAX;
        if(i>1) {
            second = dp[i-2] + abs(height[i]-height[i-1]);
        }
        dp[i]=min(first, second);
    }
    
    return dp[height.size()-1];
}

// Highly optimization as their only required previous two variables;   

int main(int argc, char** argv) {

    return 0;
}