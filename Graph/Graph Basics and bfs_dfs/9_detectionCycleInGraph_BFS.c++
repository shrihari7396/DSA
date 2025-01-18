// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends
class Solution {
  private:
    // Helper function to check for cycle using BFS
    bool check(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1; // Mark the source node as visited
        queue<pair<int, int>> q;
        q.push({src, -1}); // Start BFS with source node and parent -1

        while (!q.empty()) {
            auto it = q.front();
            int node = it.first;  // Current node
            int parent = it.second; // Parent of the current node
            q.pop();

            // Traverse all adjacent nodes
            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1; // Mark as visited
                    q.push({adjacentNode, node}); // Push adjacent node with current node as parent
                } else if (parent != adjacentNode) {
                    // If the adjacent node is visited and it's not the parent, there's a cycle
                    return true;
                }
            }
        }
        return false; // No cycle detected
    }

  public:
    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0}; // Visited array

        // Check for cycles in all components of the graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (check(i, adj, vis)) { // Pass the node `i`, not `vis[i]`
                    return true; // Cycle detected
                }
            }
        }
        return false; // No cycle found
    }
};

//{ Driver Code Starts.
int main(int argc, char**argv) {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

//  Driver Code Ends
