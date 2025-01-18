#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<pair<int, int>, int>> q; //{{x,y}, distance};
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int X[] = {-1, 0, 1, 0};
        int Y[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[row][col] = steps;
            for (int i = 0; i < 4; i++) {
                int nrow = row + X[i];
                int ncol = col + Y[i];
                if (nrow >= 0 && ncol >= 0 && nrow < mat.size() &&
                    ncol < mat[0].size() && vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return ans;
    }
};

int main(int argv, char** argc) {

    return 0;
}