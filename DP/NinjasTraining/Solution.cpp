#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int ind, vector<vector<int>>& task, int last) {
        if(ind == 0) {
            int maxi = 0;
            for(int i=0;i<3;i++) {
                maxi = max(task[ind][i], maxi);
            }
            return maxi;
        }

        int maxiScore = 0;
        for(int i=0;i<3;i++) {
            if(last != i) {
                maxiScore = max(task[ind][i] + helper(ind-1, task, i), maxiScore);
            }
        }

        return maxiScore;
    }

public:
    int CalculateMaximumPoints(vector<vector<int>>& task) {
        return helper(task.size()-1, task, 3);
    }
};

class MemoizedSolution {
private:
    int helper(int ind, vector<vector<int>>& task, int last, vector<vector<int>>& dp) {
        if(ind == 0) {
            int maxi = 0;
            for(int i = 0; i < 3; i++) {
                if(i != last) {
                    maxi = max(maxi, task[0][i]);
                }
            }
            return maxi;
        }

        if(dp[ind][last] != -1) return dp[ind][last];

        int maxScore = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                int curr = task[ind][i] + helper(ind - 1, task, i, dp);
                maxScore = max(maxScore, curr);
            }
        }

        return dp[ind][last] = maxScore;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, -1)); // last = 0, 1, 2, or 3
        return helper(n - 1, points, 3, dp); // last = 3 means no task previously done
    }

};

class TabulizedSolution {
public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        // dp[day][last] = max points till that day if 'last' task was done previously
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case: day 0
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]}); // No task done previously

        for(int day = 1; day < n; day++) {
            for(int last = 0; last < 4; last++) {
                dp[day][last] = 0; // initialize for this day and 'last'
                int maxi = 0;
                for(int task = 0; task < 3; task++) {
                    if(task != last) {
                        int point = points[day][task] + dp[day - 1][task];
                        maxi = max(maxi, point);
                    }
                }
                dp[day][last] = maxi;
            }
        }

        return dp[n - 1][3]; // max points on last day when we can choose any task
    }
};


class SpaceOptimizedSolution {
public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
    // dp[last] = max points till previous day when last task was 'last'
        vector<int> dp(4, 0);

        // Base case: day 0
        dp[0] = max(points[0][1], points[0][2]);
        dp[1] = max(points[0][0], points[0][2]);
        dp[2] = max(points[0][0], points[0][1]);
        dp[3] = max({points[0][0], points[0][1], points[0][2]}); // No task done previously

        for(int day = 1; day < n; day++) {
            vector<int> temp(4, 0);  // Temporary array for current day
            for(int last = 0; last < 4; last++) {
                int maxi = 0;
                for(int task = 0; task < 3; task++) {
                    if(task != last) {
                        int point = points[day][task] + dp[task];
                        maxi = max(maxi, point);
                    }
                }
                temp[last] = maxi;
            }
            dp = temp;  // ✅ update dp after all tasks are processed for the day
        }

        return dp[3];  // Answer is when no restriction on last task
    }

};


int main(int argc, char** argv) {

    return 0;
}