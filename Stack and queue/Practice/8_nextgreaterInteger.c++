#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterInteger(vector<int>& nums) {
    stack<int> st;
    int size = nums.size();
    vector<int> ans(size);
    for(int i = size - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(nums[i]);  
    }
    return ans;
}