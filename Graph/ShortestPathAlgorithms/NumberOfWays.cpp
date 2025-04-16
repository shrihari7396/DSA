#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto it = roads.begin(); it != roads.end(); ++it) {
                adj[(*it)[0]].push_back({(*it)[1], (*it)[2]});
                adj[(*it)[1]].push_back({(*it)[0], (*it)[2]});
            }
    
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n, 0);
            const int MOD = 1e9 + 7;
    
            pq.push({0, 0});
            dist[0] = 0;
            ways[0] = 1;
    
            while (!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                long long time = it.first;
                int node = it.second;
    
                if (time > dist[node]) continue;
    
                for (auto adjIt = adj[node].begin(); adjIt != adj[node].end(); ++adjIt) {
                    int next = adjIt->first;
                    long long newDist = time + adjIt->second;
    
                    if (newDist < dist[next]) {
                        dist[next] = newDist;
                        ways[next] = ways[node];
                        pq.push({newDist, next});
                    } else if (newDist == dist[next]) {
                        ways[next] = (ways[next] + ways[node]) % MOD;
                    }
                }
            }
            return ways[n - 1];
        }
    };
    

int main()
{
    
    return 0;
}