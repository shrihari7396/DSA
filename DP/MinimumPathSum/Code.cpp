#include <bits/stdc++.h>
using namespace std;

int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
    if (i < 0 || j < 0)
        return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

// Main function to find the minimum sum path in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}


int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}


int main(int argc, char** argv) {

    return 0;
}