#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int n = vis.size();
        int m = vis[0].size();
        q.push({row, col});
        vis[row][col] = 1;  // Mark the initial position as visited
        int X[] = {-1, 0, 1, 0, 1, -1, 1, -1};
        int Y[] = {0, -1, 0, 1, 1, -1, -1, 1};
        
        while (!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
            
            for (int i = 0; i < 8; i++) {  // Iterate over all 8 directions
                int nrow = crow + X[i];
                int ncol = ccol + Y[i];
                
                // Check for valid position and if it's land and not visited
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // Start a BFS if we find an unvisited land cell
                if (grid[row][col] == '1' && !vis[row][col]) {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution sol;
    cout << "Number of islands: " << sol.numIslands(grid) << endl;

    return 0;
}
