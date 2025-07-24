#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        int f(int i, int j, string& text1, string& text2) {
            if(i < 0 || j < 0) return 0;
            // -ve mean the end of the string

            if(text1[i] == text2[j]) {
                return 1 + f(i-1, j-1, text1, text2);
            }

            return max(f(i-1, j, text1, text2), f(i, j-1, text1, text2));

        }

        // Memoization
        int f(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
            if(i < 0 || j < 0) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            if(text1[i] == text2[j]) {
                return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
            }

            return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));

        }

        // Using Sifting of index
        int f_shift(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
            if(i == 0 || j == 0) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            if(text1[i-1] == text2[j-1]) {
                return dp[i][j] = 1 + f_shift(i-1, j-1, text1, text2, dp);
            }

            return dp[i][j] = max(f_shift(i-1, j, text1, text2, dp), f_shift(i, j-1, text1, text2, dp));

        }
        

    int tabulation(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }

    int SpaceOptimization(string text1, string text2) {
        vector<int> prev(text2.size() + 1, 0), curr(text2.size() + 1, 0);
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr; // fix: swap for next row
        }
        return prev[text2.size()];
    }

    void printing(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int m = text1.size();
        int n = text2.size();

        int length = dp[m][n];
        string ans(length, ' ');  // Easier than using raw char array

        int ind = length - 1;
        while (m > 0 && n > 0) {
            if (text1[m - 1] == text2[n - 1]) {
                ans[ind] = text1[m - 1];
                ind--;
                m--;
                n--;
            } else if (dp[m - 1][n] > dp[m][n - 1]) {
                m--;
            } else {
                n--;
            }
        }

        cout << ans << endl;
    }

    

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        return f(n1-1, n2-1, text1, text2);
    }
};
int tmp() {
    cout << " " << endl;
}
int main(int argc, char** argv) {
    // Solution s;
    // s.printing("popshf", "popsrdfpop");
    tmp();
 
    return 0;
}