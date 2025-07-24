#include <bits/stdc++.h>
using namespace std;

class SolutionMemoisation {
private:
    int helper(int i,int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
        if(i==n-1) {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int dia = triangle[i][j] + helper(i+1, j+1, triangle, n, dp);
        int down = triangle[i][j] + helper(i+1, j, triangle, n, dp);

        return dp[i][j]=min(down, dia);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0,0, triangle, n, dp);
    }
};


class SolutionTabulation {
private:
    int helper(int i,int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
        if(i==n-1) {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int dia = triangle[i][j] + helper(i+1, j+1, triangle, n, dp);
        int down = triangle[i][j] + helper(i+1, j, triangle, n, dp);

        return dp[i][j]=min(down, dia);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0;i<n;i++) {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--) {
            for(int j=i;j>=0;j--) {
                int up = dp[i+1][j]+triangle[i][j];
                int dia = dp[i+1][j+1]+triangle[i][j];

                dp[i][j] = min(up, dia);
            }
        }
        return dp[0][0];
    }
};

class SolutionSpaceOptimization {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector<int> front = triangle[n-1], curr(n,0);

        for(int i=n-2;i>=0;i--) {
            for(int j=i;j>=0;j--) {
                int up = front[j]+triangle[i][j];
                int dia = front[j+1]+triangle[i][j];

                curr[j] = min(up, dia);
            }
            front = curr;
        }
        return front[0];
    }
};

int main(int argc, char** argv) {

    return 0;
}