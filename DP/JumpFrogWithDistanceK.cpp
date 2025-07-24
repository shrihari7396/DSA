#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& steps, int n, unordered_map<int, int>& m) {
        if(n==0) return 0;
        if(m.find(n)!=m.end()) return m[n];
        int left=INT_MAX, right= INT_MAX;
        if(n>1) left = solve(steps,n-2, m) + abs(steps[n-2] - steps[n]);
        if(n>0) right = solve(steps, n-1, m) + abs(steps[n-1]-steps[n]);
        m[n]= min(left, right);
        return m[n];
    }
public:
    int frogJump(vector<int>& heights) {
        unordered_map<int, int> m;
        return solve(heights, heights.size()-1,m);
    }
};

// Meorization
class Solution {
public:
    int frogJump1(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n);
        dp[0] = 0;

        for(int i = 1; i < n; ++i) {
            int jumpOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int jumpTwo = INT_MAX;
            if(i > 1)
                jumpTwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            
            dp[i] = min(jumpOne, jumpTwo);
        }

        return dp[n - 1];
    }

    int frogJump2(vector<int>& heights) {
        int n = heights.size();
        int prev = 0, prev2 = 0;

        for(int i = 1; i < n; ++i) {
            int jumpOne = prev + abs(heights[i] - heights[i - 1]);
            int jumpTwo = INT_MAX;
            if(i > 1)
                jumpTwo = prev2 + abs(heights[i] - heights[i - 2]);

            int curr = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};


int main(int argc, char** argv) {

    return 0;
}