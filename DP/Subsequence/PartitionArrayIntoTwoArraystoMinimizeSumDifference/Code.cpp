#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    // ✅ Space Optimized DP Approach (Recommended)
    int minimumDifference(vector<int>& arr) {
        
        int totSum = 0;
        int n = arr.size();

        if (n == 0) return 0; // Early return for empty input

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        totSum = abs(totSum);

        // Initialize a boolean vector 'prev' to represent the previous row of the DP table
        vector<bool> prev(totSum + 1, false);

        // Base case: If no elements are selected (sum is 0), it's a valid subset
        // prev[0] = true;
        // Initialize the first row based on the first element of the array
        if (arr[0] <= totSum && arr[0] >= 0)
            prev[arr[0]] = true;

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            // Create a boolean vector 'cur' to represent the current row of the DP table
            vector<bool> cur(totSum + 1, false);
            cur[0] = true;

            for (int target = 1; target <= totSum; target++) {
                // Exclude the current element
                bool notTaken = prev[target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                cur[target] = notTaken || taken;
            }

            // Set 'cur' as the 'prev' for the next iteration
            prev = cur;
        }

        // Find the minimum absolute difference between two subset sums
        int mini = 1e9;
        for (int i = 0; i <= totSum / 2; i++) {
            if (prev[i] == true) {
                int diff = totSum - 2 * i;
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};


int main(int argc, char** argv) {

    return 0;
}