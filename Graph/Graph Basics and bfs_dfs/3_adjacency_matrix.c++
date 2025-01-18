#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int m, n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int v,u;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    return 0;;
}