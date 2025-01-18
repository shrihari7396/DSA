#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    
    bool dfs(int node, vector<int> adj[], int vis[], int parent) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, node)) return true;
            } else if(it != parent) {
                return true;
            }
        }
        return false;
    }

public:

    bool cycleDetectionInGraph(vector<int> adj[], int V) {
        int vis[V] = {0};
        for(int i = 0; i < V; i++) {
            if(dfs(i,adj,vis,-1)) {
                return true;
            }
        }
        return false;
    }

};

int main(int argv, char** argc) {

    return 0;
}