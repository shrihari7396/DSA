#include <bits/stdc++.h>
using namespace std;

class Solution {
    //Memoization 
    // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    int helper(int m, int n, vector<vector<int>>& dp) {
        if(m==1 && n==1) return 1;

        if(m<1 || n<1) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = helper(m-1, n, dp) + helper(m, n-1, dp);
    }

    
    public:
    int uniquePahtsSpaceOptimization(int m, int n) {
        vector<int> prev(n,0);

        for(int i=1;i<m+1;i++) {
            vector<int> curr(n, 0);
            for(int j=1;j<n+1;j++) {
                if(i==0 && j==0) curr[j]=1;
                else {
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
    
    // Tabulation 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        for(int i=1;i<m+1;i++) {
            for(int j=1;j<n+1;j++) {
                if(i==1 && j==1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

class SolutionPartTwo {

public:
    class Solution {
        // Memoization
        int helper(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obs) {
            if (m < 1 || n < 1 || obs[m-1][n-1] == 1) return 0;
            if (m == 1 && n == 1) return 1;

            if (dp[m][n] != -1) return dp[m][n];

            return dp[m][n] = helper(m-1, n, dp, obs) + helper(m, n-1, dp, obs);
        }

    public:
        // Space Optimized
        int uniquePathsSpaceOptimization(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

            vector<int> prev(n+1, 0);

            for (int i = 1; i <= m; i++) {
                vector<int> curr(n+1, 0);
                for (int j = 1; j <= n; j++) {
                    if (obstacleGrid[i-1][j-1] == 1) curr[j] = 0;
                    else if (i == 1 && j == 1) curr[j] = 1;
                    else {
                        curr[j] = prev[j] + curr[j-1];
                    }
                }
                prev = curr;
            }

            return prev[n];
        }

        // Tabulation
        int uniquePaths(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
            dp[1][1] = 1;

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == 1 && j == 1) continue;
                    if (obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }

            return dp[m][n];
        }

        // Memoization wrapper
        int uniquePathsMemoization(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

            vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
            return helper(m, n, dp, obstacleGrid);
        }
    };
};