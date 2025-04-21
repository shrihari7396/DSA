#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to perform DFS from a given node
    void DFS(int node, vector<int>& vis, vector<int> adj[], vector<int>& dfs) {
        vis[node] = 1;           // Mark the current node as visited
        dfs.emplace_back(node);   // Add it to the DFS result

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) {
                DFS(it, vis, adj, dfs);  // Recursively perform DFS
            }
        }
        return ;
    }

public:
    // Function to return DFS traversal from node 0
    vector<int> dfsTraversal(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);    // Visited array initialized to 0
        vector<int> dfs;          // To store the DFS traversal

        for(int i=0;i<v;i++) {    // Start DFS from node 0
            if(!vis[i]) {
                DFS(i, vis, adj, dfs);
            }
        }

        return dfs;               // Return the traversal result
    }
};
