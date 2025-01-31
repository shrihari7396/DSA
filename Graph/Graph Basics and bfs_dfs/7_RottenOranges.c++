#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0, total=0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1) {
                    total++;
                }
            }
        }

        int row[] = {-1,0,1,0};
        int col[] = {0, -1, 0 , 1};
        int ans=0;
        while(!q.empty()) {
            auto it = q.front();q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int t=it.second;
            ans=max(t,ans);

            for(int i=0;i<4;i++) {
                int row1=row[i]+x;
                int col1=col[i]+y;
                if(row1>=0 && row1<m && col1>=0 && col1<n && vis[row1][col1]==0 && grid[row1][col1]==1) {
                    q.push({{row1, col1}, t+1});
                    vis[row1][col1]=2;
                    cnt++;
                }
            }
        }

        if(cnt != total) return -1;
        return ans;
    }
};