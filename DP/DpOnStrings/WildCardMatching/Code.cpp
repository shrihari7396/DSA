#include <bits/stdc++.h>
using namespace std;

class Memoisation {
private:
    bool f(int i, int j, string& p, string& s) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0)  return false;
        if(j < 0 && i >= 0) {
            for(int ii = 0; ii <= i; ii++) {
                if(p[ii]!='*') return false;
            }
            return true;
        } 

        if(p[i] == s[j] || p[i] == '?') return f(i-1 , j-1,  p, s);

        if(p[i] == '*') return f(i-1, j, p, s) | f(i, j-1, p, s);

        return false;
    }

    bool f_Memoization(int i, int j, string& p, string& s, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0) {
            for(int ii = 1; ii <= i; ii++) {
                if(p[ii - 1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[i - 1] == s[j - 1] || p[i - 1] == '?')
            return dp[i][j] = f_Memoization(i - 1, j - 1, p, s, dp);

        if(p[i - 1] == '*')
            return dp[i][j] = f_Memoization(i - 1, j, p, s, dp) || f_Memoization(i, j - 1, p, s, dp);

        return dp[i][j] = false;
    }

    
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size() + 1, vector<int> (s.size() + 1, -1));
        return f_Memoization(p.size(), s.size(), p, s, dp);
    }
};

class Tabulation {
private:
    bool isAllStars(string &S1, int i) {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

    // Function to perform wildcard pattern matching between S1 and S2
    bool wildcardMatching(string &S1, string &S2) {
        int n = S1.size();
        int m = S2.size();

        // Create a DP table to memoize results
        vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

        // Initialize the first row and column
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = isAllStars(S1, i);
        }

        // Fill in the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if (S1[i - 1] == '*') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        // The value at dp[n][m] contains whether S1 matches S2
        return dp[n][m];
    }
};



class SpaceOptimization {
    // Function to check if a substring of S1 contains only '*'
    bool isAllStars(string &S1, int i) {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

    // Function to perform wildcard pattern matching between S1 and S2
    bool wildcardMatching(string &S1, string &S2) {
        int n = S1.size();
        int m = S2.size();

        // Create two arrays to store previous and current rows of matching results
        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        prev[0] = true; // Initialize the first element of the previous row to true

        for (int i = 1; i <= n; i++) {
            cur[0] = isAllStars(S1, i); // Initialize the first element of the current row
            for (int j = 1; j <= m; j++) {
                if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                    cur[j] = prev[j - 1]; // Characters match or S1 has '?'
                } else {
                    if (S1[i - 1] == '*') {
                        cur[j] = prev[j] || cur[j - 1]; // '*' represents empty or a character
                    } else {
                        cur[j] = false; // Characters don't match and S1[i-1] is not '*'
                    }
                }
            }
            prev = cur; // Update the previous row with the current row
        }

        // The value at prev[m] contains whether S1 matches S2
        return prev[m];
    }
};

int main(int argc, char** argv) {

    return 0;
}