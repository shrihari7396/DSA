#include <bits/stdc++.h>
using namespace std;


class Solution {
        vector<int> findNse(const vector<int>& nums) {
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

    vector<int> findPse(const vector<int>& nums) {
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
    int largestRectangleArea(vector<int>& nums) {
        vector<int> pse = findPse(nums);
        vector<int> nse = findNse(nums);
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int width = nse[i] - pse[i] - 1;
            // Area is height (nums[i]) multiplied by width
            int area = nums[i] * width;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};

// Optimizatio in above code
class Solution_1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // Stack to store indices of the histogram
        int maxArea = 0; // Variable to keep track of the maximum area
        int size = heights.size(); // Size of the input vector

        for (int i = 0; i < size; i++) {
            // While there is a height that is greater than the current height
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()]; // Height of the rectangle
                st.pop(); // Remove the index from the stack
                int nse = i; // Next smaller element index
                int pse = st.empty() ? -1 : st.top(); // Previous smaller element index
                // Calculate the area with heights[element] as the smallest height
                maxArea = max(maxArea, (nse - pse - 1) * element);
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Process any remaining indices in the stack
        while (!st.empty()) {
            int nse = heights.size(); // Assume the next smaller element is at the end
            int element = st.top(); // Get the top element index
            st.pop(); // Remove the index from the stack
            int pse = st.empty() ? -1 : st.top(); // Previous smaller element index
            // Calculate the area for the remaining elements in the stack
            maxArea = max(maxArea, (nse - pse - 1) * heights[element]);
        }
        return maxArea; // Return the maximum area
    }
};

int main(void) {

    return 0;
}