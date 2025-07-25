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

    bool dfs(int i, vector<bool>& vis, vector<bool>& path, vector<int> adj[]) {
        vis[i] = true;
        path[i] =  true;
        for(auto &it : adj[i]) {
            if(!vis[it]) {
                if(dfs(it, vis, path, adj)) {
                    return true;
                }
            } else if(path[it]) return true;
        }
        path[i] = false;
        return false;
    }

    // Khan's Algorithm
    bool bfs(vector<vector<int>> adj) {
        int n = adj.size();
        vector<int> topo(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto it1 : adj[i]) {
                topo[it1] ++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if(topo[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            int node = q.front();q.pop();
            ans.emplace_back(node);
            for(auto& it : adj[node]) {
                topo[it] --;
                if(topo[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return ans.size() == n;
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