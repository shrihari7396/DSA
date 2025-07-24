#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return shortest distances from source node
    vector<int> getShortestDistances(vector<vector<pair<int, int>>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int d = top.first;
            int node = top.second;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    // Function to return the shortest path from src to dest
    vector<int> getShortestPath(vector<vector<pair<int, int>>>& adj, int src, int dest) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
            parent[i] = i;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int d = top.first;
            int node = top.second;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[dest] == INT_MAX)
            return {-1}; // No path found

        vector<int> path;
        int current = dest;
        while (parent[current] != current) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};

// Example usage
int main() {
    int V = 6; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Add undirected edges with weights
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    
    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    adj[3].push_back({5, 1});
    adj[5].push_back({3, 1});

    adj[4].push_back({5, 5});
    adj[5].push_back({4, 5});

    Solution sol;
    int src = 0, dest = 5;

    // Print shortest distances
    vector<int> dist = sol.getShortestDistances(adj, src);
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "Unreachable\n";
        else cout << dist[i] << "\n";
    }

    // Print shortest path from src to dest
    vector<int> path = sol.getShortestPath(adj, src, dest);
    cout << "\nShortest path from " << src << " to " << dest << ":\n";
    if (path[0] == -1)
        cout << "No path exists.\n";
    else {
        for (int node : path)
            cout << node << " ";
        cout << "\n";
    }

    return 0;
}
