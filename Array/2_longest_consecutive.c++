#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.empty()) return 0;
        int lastSmaller = INT_MIN;
        int n = nums.size();
        int cnt = 0;
        int longest = 1;
        for(int i = 0; i < n; i++) 
        {
            if(nums[i] - 1 == lastSmaller) {
                cnt += 1;
                lastSmaller = nums[i];
            } else if(lastSmaller != nums[i]) {
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

class Solution_2 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        unordered_set<int> s;
        s.insert(nums.begin(), nums.end());
        int longest = 1;
        for(auto ch : s) {
            if(s.find(ch - 1) == s.end()) {
                int cnt = 1;
                int x = ch;
                while(s.find(x+1) != s.end()) {
                    cnt += 1;
                    x = x + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
