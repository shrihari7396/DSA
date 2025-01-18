#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int x, int y, vector<vector<int>>& mat, vector<vector<int>>&vis, int delrow[], int delcol[]) {
        vis[x][y] = 1;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, mat, vis, delrow, delcol);
            }
        }
    }
public:
    void surroundedRegions(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i = 0; i < n; i++) {
            // First row of the matrix
            if(!vis[0][i] && mat[0][i] == 'O') {
                dfs(0, i, mat, vis, delrow, delcol);
            }
            // Last row of the matrix
            if(!vis[m-1][i] && mat[m-1][i] == 'O') {
                dfs(m-1, i, mat, vis, delrow, delcol);
            }
        }

        for(int i = 0; i < n; i++) {
            // First column of the matrix
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, mat, vis, delrow, delcol);
            }
            // Last column of the matrix
            if(!vis[i][n-1] && mat[i][n-1] == 'O') {
                dfs(i, n-1, mat, vis, delrow, delcol);
            }
        }

        // Updating the given matrix according the given condition in the question
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};

int main(int argv, char** argc) {

    return 0;
}