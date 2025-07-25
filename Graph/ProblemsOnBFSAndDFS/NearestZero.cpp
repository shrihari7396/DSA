#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> f(vector<int> adj[], vector<vector<bool>>& vis) {
        int m = adj->size();
        int n = adj[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int t = it.second;
            int x = it.first.first;
            int y = it.first.second;

            for(int i = 0; i < 4; i++) {
                int xnew = x + dx[i];
                int ynew = y + dy[i];

                if(xnew < m && xnew >= 0 && ynew >= 0 && ynew < n && !vis[xnew][ynew] && adj[xnew][ynew]) {
                    q.push({{xnew, ynew}, t+1});
                    ans[xnew][ynew] = t+1;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {

}