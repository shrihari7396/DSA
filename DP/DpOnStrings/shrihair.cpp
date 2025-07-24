#include<bits/stdc++.h>
using namespace std;

vector<int> findShortestPath(int V, int E, int paths[][3], int pairs[][2], int colorNumber) {
    // Build adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u = paths[i][0];
        int v = paths[i][1];
        int w = paths[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // Get source and destination from color
    int src = pairs[colorNumber - 1][0];
    int dest = pairs[colorNumber - 1][1];
    
    // Dijkstra's algorithm
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    int current = dest;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int paths[E][3];
    for (int i = 0; i < E; i++) {
        cin >> paths[i][0] >> paths[i][1] >> paths[i][2];
    }
    
    int numPairs = (V % 2 == 0) ? V / 2 : (V / 2) + 1;
    int pairs[numPairs][2];
    
    for (int i = 0; i < V / 2; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    
    if (V % 2 == 1) {
        int leftover;
        cin >> leftover;
        pairs[V / 2][0] = leftover;
        pairs[V / 2][1] = leftover; // This will be handled as no path case
    }
    
    int colorNumber;
    cin >> colorNumber;
    
    vector<int> result = findShortestPath(V, E, paths, pairs, colorNumber);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
