#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(int i, int j, string s1, string s2) {
        if(i < 0 || j < 0) return 0;

        if(s1[i] == s2[j]) return 1 + longestCommonSubsequence(i-1, j-1, s1, s2);

        return max(longestCommonSubsequence(i-1, j, s1, s2), longestCommonSubsequence(i, j-1, s1, s2));
    }

public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        string s1 = s;

        return longestCommonSubsequence(s1.size()-1, s2.size()-1, s1, s2);
        
    }
};