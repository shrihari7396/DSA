#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCycle(vector<int> adj[], vector<int> vis) {
        
        queue<pair<int, int>> q;
        q.push({0,-1});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int parent = it.second;

            for(auto s : adj[node]) {
                if(!vis[s]) {
                    q.push({s, node});
                    vis[s] = true;
                } else if(parent != s) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(dfs(it, node, adj, vis)) return true;
            else if(parent != it) return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    int n;

    return 0;
}