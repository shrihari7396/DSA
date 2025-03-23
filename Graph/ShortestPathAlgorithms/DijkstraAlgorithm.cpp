#include <bits/stdc++.h>
using namespace std;

// User Function Template
class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> parent(adj.size() + 1), dist(adj.size(), INT_MAX);

        for (int i = 0; i < adj.size() + 1; i++) {
            parent[i] = i;
        }

        pq.push({0, 1});
        dist[1] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first; // Adjacent node
                int edW = it.second;    // Edge weight

                if (edW + wt < dist[adjNode]) {
                    dist[adjNode] = wt + edW;
                    pq.push({dist[node], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[adj.size()] == INT_MAX)
            return {-1};
        vector<int> path;
        int node = adj.size();
        while (parent[node] != node) {
            path.emplace_back(node);
            node = parent[node];
        }
        return path;
    }

    vector<int> dis(vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(adj.size(), INT_MAX), parent(adj.size() + 1);

        for (int i = 0; i < adj.size(); i++) {
            parent[i] = i;
        }
        pq.push({1, 0});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            for (auto it : adj[node]) {
                int edw = it.second;
                int adjNode = it.first;
                if (edw + wt < dist[adjNode]) {
                    dist[adjNode] = edw + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dist[adj.size()] == INT_MAX)
            return {-1};
        vector<int> path;
        int it = adj.size();
        while (it >= 0 && dist[it] != it) {
            path.emplace_back(dist[it]);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main(int argc, char** argv) { return 0; }