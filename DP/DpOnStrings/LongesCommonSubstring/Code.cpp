#include <bits/stdc++.h>
using namespace std;


class Solution
{

    int tabulation(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }

    int spaceOptimization(string& text1, string &text2) {
        int n = text1.size();
        int m = text2.size();
        int maxi = 0;
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i] == text2[j]) {
                    curr[j] = prev[j-1] + 1;
                    maxi = max(curr[j], maxi);
                }
                else curr[j] = 0;
            }
            prev = curr;
        } 
        return maxi;
    }

};

int main(int argc, char** argv) {

    return 0;
}