#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int check(int n, int x, int y) {
            return x>=0 && y>=0 && x<n && y<n;
        }
    
        int helper(pair<int, int>& src, pair<int, int>& des, vector<vector<int>>& grid) {
            queue<pair<int, pair<int, int>>> q;
            vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(), INT_MAX));
    
            int xinc[] = {1,-1,0,0,1,-1,-1,1};
            int yinc[] = {0,0,-1,1,1,-1,1,-1};
    
            q.push({1,{src.first, src.second}});
            dist[src.first][src.second]=0;
            int n=grid.size();
    
            while(!q.empty()) {
                auto it = q.front();
                int wt = it.first;
                int x=it.second.first;
                int y=it.second.second;
                q.pop();
    
                for(int i=0;i<8;i++) {
                    int xNew = x+xinc[i];
                    int yNew = y+yinc[i];
                    if(check(n, xNew, yNew) && !grid[xNew][yNew] && dist[xNew][yNew]>wt+1) {
                        dist[xNew][yNew] = wt+1;
                        q.push({dist[xNew][yNew], {xNew, yNew}});
                    }
                }
            }
            if(dist[n-1][n-1]==INT_MAX) return -1;
            return dist[n-1][n-1]; 
        }
    
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            pair<int, int> src = {0, 0};
            pair<int, int> des = {n - 1, n - 1};
            if(grid.size()==1 && grid[0][0]==0) return 1;
            if(grid[0][0]==1) return -1;
            return helper(src, des, grid);
        }
    };