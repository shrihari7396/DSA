#include <bits/stdc++.h>
using namespace std;

class SolutionDFS {
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int ncol[], int nrow[]) {
        if (vis[x][y])
            return;
        vis[x][y] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nx = x + nrow[i];
            int ny = y + ncol[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] &&
                grid[nx][ny]) {
                dfs(nx, ny, grid, vis, ncol, nrow);
            }
        }
        return;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int ncol[] = {-1, 1, 0, 0};
        int nrow[] = {0, 0, -1, 1};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0;  i < n; i++) {
            if(!vis[0][i] && grid[0][i]) {
                dfs(0,i,grid,vis,ncol,nrow);
            }
            if(!vis[m-1][i] && grid[m-1][i]) {
                dfs(m-1,i,grid,vis,ncol,nrow);
            }
        }

        for(int i = 0; i < m; i++) {
            if(!vis[i][0] && grid[i][0]) {
                dfs(i, 0, grid,vis,ncol, nrow);
            }
            if(!vis[i][n-1] && grid[i][n-1]) {
                dfs(i, n-1, grid, vis, ncol, nrow);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j])
                    count++;
            }
        }
        return count;
    }
};

class SolutionBFS {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0)); // Visited matrix
        queue<pair<int, int>> q; // Queue for BFS

        // Directions for moving up, left, down, right
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, -1, 0, 1};

        // Traverse the first and last columns of the grid
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if (grid[i][n - 1] == 1 && !vis[i][n - 1]) {
                vis[i][n - 1] = 1;
                q.push({i, n - 1});
            }
        }

        // Traverse the first and last rows of the grid
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                vis[0][i] = 1;
                q.push({0, i});
            }
            if (grid[m - 1][i] == 1 && !vis[m - 1][i]) {
                vis[m - 1][i] = 1;
                q.push({m - 1, i});
            }
        }

        // Perform BFS to mark all connected land cells from the borders
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int xn = x + nrow[i];
                int yn = y + ncol[i];
                
                // If the new position is valid, land, and not visited, mark it
                if (xn >= 0 && yn >= 0 && xn < m && yn < n && grid[xn][yn] == 1 && !vis[xn][yn]) {
                    vis[xn][yn] = 1;  // Mark the neighbor as visited
                    q.push({xn, yn});  // Push it into the queue for further exploration
                }
            }
        }

        // Count the number of enclaves (land cells that are not visited)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;  // Count unvisited land cells
                }
            }
        }

        return count;  // Return the number of enclaves
    }
};


int main(int argc, char** argv) {

    return 0;   
}