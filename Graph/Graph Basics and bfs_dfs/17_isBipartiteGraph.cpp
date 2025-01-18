#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = col;
        for (auto it : graph[node]) {
            if (vis[it] == -1) {
                if (!dfs(it, !col, graph, vis)) return false;
            } else if (vis[it] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, 0, graph, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {

    return 0;
}