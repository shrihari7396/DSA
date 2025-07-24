#include <bits/stdc++.h> 
using namespace std;

int mod = (int) (1e9 + 7);

class SolutionWithMemoiation {
private:
    int f(int i, int target, vector<int>& nums, 
        vector<vector<int>>& dp) {
        if(i==0) {
            if(target == 0 && nums[0] == 0) return dp[i][target] = 2;
            if(target == 0 || nums[0]==target) return dp[i][target] = 1;
            return dp[i][target] = 0;
        }

        if(dp[i][target]!=-1) {
            return dp[i][target];
        }

        int notTake = f(i-1, target, nums, dp);
        int take = 0;
        if(target >= nums[i]) {
            take = f(i-1, target - nums[i], nums, dp);
        }

        return dp[i][target] = (take + notTake)%mod;
    }

    int callFunction(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return f(n-1, target, nums, dp);
    }

public:
    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int totalSum = 0;
        for(int i=0;i<n;i++) {
            totalSum += arr[i];
        }

        /*  
            s1 = sum of elements of first subset
            s2 = sum of elements of second subset
            s1 + s2 = totalSum

            s1 - s2 = D  ->  Assume s1 > s2
            totalSum - s2 - s2 = D
            s2 = (totalSum - D)/2;

            target = s2;
            we have to find only number of subset with sum s2

            // EdgeCases:-

            (totalSum - D) -> should be positive and it should even so we can get proper iteger after division by 2

        */
        int x = (totalSum - d);
        if(x%2==1 || x < 0) return 0;
        
        int target = x / 2;

        return callFunction(arr, target);
    }


};

class SolutionWithTabulation {
private:
    int f(int i, int target, vector<int>& nums, 
        vector<vector<int>>& dp) {
        if(i==0) {
            if(target == 0 && nums[0] == 0) return dp[i][target] = 2;
            if(target == 0 || nums[0]==target) return dp[i][target] = 1;
            return dp[i][target] = 0;
        }

        if(dp[i][target]!=-1) {
            return dp[i][target];
        }

        int notTake = f(i-1, target, nums, dp);
        int take = 0;
        if(target >= nums[i]) {
            take = f(i-1, target - nums[i], nums, dp);
        }

        return dp[i][target] = (take + notTake)%mod;
    }

    // Tabulation of the above recursion
    int callFunction(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        // Base case setup
        if(nums[0] == 0) {
            dp[0][0] = 2; // {}, {0}
        } else {
            dp[0][0] = 1; // only {}
            if(nums[0] <= target)
                dp[0][nums[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= target; tar++) {
                int notTake = dp[ind-1][tar];
                int take = 0;
                if(tar >= nums[ind]) {
                    take = dp[ind-1][tar - nums[ind]];
                }
                dp[ind][tar] = (take + notTake) % mod;
            }
        }

        return dp[n-1][target];
    }

    // SpaceOptimzation
    int callFunction(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        vector<int>prev(target+1, 0), curr(target+1, 0);
        // Base case setup
        if(nums[0] == 0) {
            prev[0] = 2; // {}, {0}
        } else {
            prev[0] = 1; // only {}
            if(nums[0] <= target)
                prev[nums[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= target; tar++) {
                int notTake = prev[tar];
                int take = 0;
                if(tar >= nums[ind]) {
                    take = prev[tar - nums[ind]];
                }
                curr[tar] = (take + notTake) % mod;
            }
            prev = curr;
        }

        return prev[target];
    }

public:
    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int totalSum = 0;
        for(int i=0;i<n;i++) {
            totalSum += arr[i];
        }

        /*  
            s1 = sum of elements of first subset
            s2 = sum of elements of second subset
            s1 + s2 = totalSum

            s1 - s2 = D  ->  Assume s1 > s2
            totalSum - s2 - s2 = D
            s2 = (totalSum - D)/2;

            target = s2;
            we have to find only number of subset with sum s2

            // EdgeCases:-

            (totalSum - D) -> should be positive and it should even so we can get proper iteger after division by 2

        */
        int x = (totalSum - d);
        if(x%2==1 || x < 0) return 0;
        
        int target = x / 2;

        return callFunction(arr, target);
    }
};



class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();

        for(int i=0;i<n;i+=k) {    
            string tmp = s.substr(i,k);
            ans.emplace_back(tmp);
        }

        if(n%k==0) return ans;

        int size = n - n%k;
    }
};