#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for(int i=0; i<V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        vector<int>topo;

        while(!q.empty()) {
            int node = q.front();q.pop();
            topo.emplace_back(node);
            // Node is in toposort so please remove it for the indegree
            for(auto it : adj[node]) {
                indegree[it]--;
                if(!indegree[it]) {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main(int argc, char** argv) {

    return 0;
}