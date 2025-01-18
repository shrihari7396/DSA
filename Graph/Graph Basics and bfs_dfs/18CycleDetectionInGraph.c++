#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis)) return true;
            } 
            // If the node has been priviously visited
            // but it has to be on same path
            else if(pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool detectCycle(vector<int> adj[], int V) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                if(dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

int main(int argc, char** argv) {

    return 0;
}