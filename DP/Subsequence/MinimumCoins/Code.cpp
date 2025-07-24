#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target%nums[0] == 0) {
                return dp[i][target] = target / nums[0];
            } 
            return 1e9;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        int notTake = f(i-1, nums, target, dp); 
        int take = INT_MAX;
        if(target >= nums[i]) {
            take = 1 + f(i, nums, target - nums[i], dp);
        }

        return dp[i][target] = min(take, notTake);
    }
public:

    // Memoisation
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }

    int coinChangeTabulation(vector<int>& coins, int amount)  {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        for(int i=0;i<=amount;i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0];
            }
        }

        for(int ind = 1; ind<n; ind++) {
            for(int tar = 0; tar <= amount; tar++) {
                int notTake = dp[ind-1][tar]; 
                int take = INT_MAX;
                if(tar >= coins[ind]) {
                    take = 1 + dp[ind][tar - coins[ind]];
                }

                dp[ind][tar] = min(take, notTake);
            }
        }

        return dp[n][amount];
    }

    int coinChangeSpaceOptimisation(vector<int>& coins, int amount)  {
        int n = coins.size();
        vector<int> prev(amount + 1, 1e9),curr(amount + 1, 1e9);
        for(int i=0;i<=amount;i++) {
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0];
            }
        }

        curr = prev;

        for(int ind = 1; ind<n; ind++) {
            for(int tar = 0; tar <= amount; tar++) {
                int notTake = prev[tar]; 
                int take = INT_MAX;
                if(tar >= coins[ind]) {
                    take = 1 + curr[tar - coins[ind]];
                }

                curr[tar] = min(take, notTake);
            }
            prev = curr;
        }

        return prev[amount];
    }
};

int main(int argc, char** argv) {

    return 0;
}