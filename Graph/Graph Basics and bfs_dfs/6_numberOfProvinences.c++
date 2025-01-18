#include <vector>
using namespace std;

class Solution {
private:
    // Depth-First Search function to mark all cities connected to 'Node'
    void dfs(int Node, vector<int> adj[], vector<int>& vis) {
        vis[Node] = 1;  // Mark the current node as visited
        
        // Traverse all directly connected nodes
        for (auto it : adj[Node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);  // Recursively visit all unvisited neighbors
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int size = nums.size();
        vector<int> adjL[size];   // Adjacency list
        
        // Build the adjacency list from the matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (nums[i][j] == 1 && i != j) {
                    adjL[i].emplace_back(j);
                }
            }
        }
        
        vector<int> vis(size, 0); // Visited array
        int count = 0;
        
        // Perform DFS for each city
        for (int i = 0; i < size; i++) {
            if (!vis[i]) {
                count++;  // Each DFS represents a new province
                dfs(i, adjL, vis);  // Start DFS from the unvisited city
            }
        }
        
        return count;  // Return the total number of provinces
    }
};
