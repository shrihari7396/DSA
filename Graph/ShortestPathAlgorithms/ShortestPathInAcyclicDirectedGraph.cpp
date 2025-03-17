#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void topoSort(int node, vector<int>&vis, vector<pair<int,int>>adj[], stack<int>& st) {
        vis[node]=1;
        for(auto it:adj[node]) {
            if(!vis[it.first]) {
                topoSort(it.first, vis, adj, st);
            }
        }
        st.push(node);
    }
    public:
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
            vector<pair<int,int>> adj[V];
            for(int i=0;i<E;i++) {
                int u=edges[i][0];
                int v=edges[i][1];
                int w=edges[i][2];
                adj[u].push_back({v,w});
            }

            vector<int> vis(V,0);
            stack<int> st;
            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    topoSort(i, vis, adj, st);
                }
            }

            int node = st.top();
            vector<int> dist(V, INT_MAX);
            dist[node]=0;

            while(!st.empty()) {
                node = st.top();
                st.pop();
                for(auto it: adj[node]) {
                    if(dist[it.first] > dist[node]+it.second) {
                        dist[it.first]=dist[node]+it.second;
                    }
                }
            }

            for(auto &it:dist){ 
                if(it==INT_MAX) {
                    it=-1;
                }
            }
            return dist;
        }
  };