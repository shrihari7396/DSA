#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<vector<int>> reverse(n);
        vector<int> indegrees(n, 0);

        for(int i = 0; i < n; i++) {
            for(auto& it : graph[i]) {
                reverse[it].emplace_back(i);
                indegrees[i]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegrees[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();q.pop();
            ans.emplace_back(node);

            for(auto& it : reverse[node]) {
                indegrees[it] --;
                if(indegrees[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};