#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initialize a visited array to track visited nodes
        vector<int> vis(V, 0); // Use vector for dynamic size
        vector<int> bfs; // To store the BFS traversal result
        queue<int> q; // Queue to facilitate BFS

        // Start BFS from node 0
        q.push(0);
        vis[0] = 1; // Mark the starting node as visited

        // Perform BFS
        while(!q.empty()) {
            int node = q.front(); // Get the front node
            q.pop(); // Remove the front node from the queue
            bfs.emplace_back(node); // Add the node to BFS result

            // Explore all adjacent nodes
            for(auto it : adj[node]) {
                // Check if the adjacent node has not been visited
                if(!vis[it]) { // Change 'node' to 'it'
                    vis[it] = 1; // Mark the adjacent node as visited
                    q.push(it); // Add the adjacent node to the queue
                }
            }
        }
        return bfs; // Return the BFS traversal result
    }
    ~Solution();
};