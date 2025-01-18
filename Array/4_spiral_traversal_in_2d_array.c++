#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> ans;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                ans.emplace_back(matrix[top][i]);
            }
            top ++;

            for(int i = top; i <= bottom; i++) {
                ans.emplace_back(matrix[i][right]);
            }
            right --;

            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                ans.emplace_back(matrix[bottom][i]);
                }
                bottom --;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                ans.emplace_back(matrix[i][left]);
                }
                left ++;
            }
        }
        return ans;
    }
};