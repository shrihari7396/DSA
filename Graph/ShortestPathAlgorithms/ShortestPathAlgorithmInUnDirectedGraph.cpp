#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> shortestPathInUndirectedGraph(vector<vector<int>>& adj) {
        vector<int> dist(adj.size(),INT_MAX);
        queue<int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(dist[node]+1 < dist[it]) {
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        for(auto &it: dist) {
            if(it==INT_MAX) it=-1;
        }
        return dist;
    }
};

int main() {
    
    return 0;
}