#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    vector<int> findNse(vector<int>& nums) {
        vector<int> nse(nums.size());
        int n = nums.size();
        stack<int> st;
        // Loop from right to left
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPse(vector<int>& nums) {
        vector<int> pse(nums.size());
        int n = nums.size();
        stack<int> st;
        // Loop from left to right
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        int total = 0;
        int mod = 1e9 + 7;
        
        for(int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];  // Elements to the left that contribute
            int right = nse[i] - i; // Elements to the right that contribute
            total = (total + (long long)arr[i] * left * right) % mod;
        }
        return total;
    }
};

int main(void) {

    return 0;
}