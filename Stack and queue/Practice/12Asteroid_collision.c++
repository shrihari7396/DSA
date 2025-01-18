#include <bits/stdc++.h>
using namespace std;

vector<int> colllsion(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(nums[i] > 0) {
            ans.emplace_back(nums[i]);
        } else {
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(nums[i])) {
                ans.pop_back();
            }
            if(!ans.empty() && ans.back() == abs(nums[i])) {
                ans.pop_back();
            } else if(ans.empty() || ans.back() < 0) {
                ans.emplace_back(nums[i]);
            }
        }
    }
    return ans;
}

int main(void) {

    return 0;
}