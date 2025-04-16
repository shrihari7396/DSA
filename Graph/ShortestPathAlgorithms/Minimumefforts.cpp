#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool check(int i, int j, vector<vector<int>>& nums) {
            return i >= 0 && i < nums.size() && j >= 0 && j < nums[0].size();
        }
    
        int helper(vector<vector<int>>& nums, int m, int n) {
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            priority_queue<pair<int, pair<int, int>>,
                           vector<pair<int, pair<int, int>>>,
                           greater<pair<int, pair<int, int>>>>
                pq;
    
            int x_inc[] = {0, 0, -1, 1};
            int y_inc[] = {1, -1, 0, 0};
            dist[0][0]=0;
            pq.push({0, {0, 0}});
    
            while (!pq.empty()) {
                auto it = pq.top();
                int effort = it.first;
                int x = it.second.first;
                int y = it.second.second;
                pq.pop();
    
                if (x == n - 1 && y == m - 1)
                    return effort;
    
                for (int i = 0; i < 4; i++) {
                    int xnew = x_inc[i] + x;
                    int ynew = y_inc[i] + y;
    
                    if (check(xnew, ynew, nums)) {
                        int newEffort = max(effort, abs(nums[xnew][ynew]-nums[x][y]));
                        if(newEffort < dist[xnew][ynew]) {
                            dist[xnew][ynew] = newEffort;
                            pq.push({newEffort, {xnew, ynew}});
                        }
                    }
                }
            }
            return -1;
        }
    
    public:
        int minimumEffortPath(vector<vector<int>>& nums) {
            int n = nums.size();
            int m = nums[0].size();
    
            return helper(nums, m, n);
        }
    };



    int main()
    {
        
        return 0;
    }