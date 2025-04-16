#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k) continue; // Only allow exactly 'k' stops

            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int ewt = neighbor.second;

                if (cost + ewt < dist[adjNode]) {
                    dist[adjNode] = cost + ewt;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};

int main(int argc, char** argv) {


    return 0;
}