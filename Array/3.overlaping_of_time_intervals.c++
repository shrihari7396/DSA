#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> overlaped_vector(vector<vector<int>>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        if(ans.empty() || ans.back()[1] < nums[i][1]) {
            ans.emplace_back(nums[i][0]);
        }else{
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
    }
}
int main(void) {
    vector<vector<int>> v = {{1,3},{3,4},{5,8}};    
    for (const auto& row : v) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}