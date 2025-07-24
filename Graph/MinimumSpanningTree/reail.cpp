#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string reversed = s;
        int i = 0, j = 0;
        string ans = "";
        int maxSize = 0;
        while(i < s.size() && j < s.size()) {
            if(s[i++] != reversed[j++]) continue;
            while(i < s.size() && j < s.size()) {
                if(s[j] == reversed[j]) j++;
                else if(maxSize < j-i+1) {
                    ans = s.substr(i, j-i+1);
                }
                i = j;
            }   
        }
        return ans;
    }
};
