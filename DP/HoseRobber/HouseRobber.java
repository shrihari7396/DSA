
import java.util.Arrays;

public class HouseRobber {
    public static void main(String[] args) {
        Solution s=new  Solution();
        System.out.println(s);
        
    }   
} 

class Solution {

    static int solveUtil(int ind, int[] arr, int[] dp) {
        // If the index is negative, there are no elements left to consider.
        if (ind < 0) return 0;
        
        // If the index is 0, there is only one element to consider, so return its value.
        if (ind == 0) return arr[ind];
        
        // If we have already calculated the result for this index, return it.
        if (dp[ind] != -1) return dp[ind];
        
        // Calculate the maximum sum by either picking the current element or not picking it.
        int pick = arr[ind] + solveUtil(ind - 2, arr, dp);
        int nonPick = solveUtil(ind - 1, arr, dp);
        
        // Store the maximum of the two options in the dp array for future reference.
        return dp[ind] = Math.max(pick, nonPick);
    }
    
    // Tabulation
    static int solveUtil1(int n, int[] arr, int[] dp) {
        // Initialize the dp array with the first element of the input array.
        dp[0] = arr[0];

        // Iterate through the input array to fill the dp array.
        for (int i = 1; i < n; i++) {
            // Calculate the maximum sum by either picking the current element or not picking it.
            int pick = arr[i];
            
            // If there are at least two elements before the current element, add the value from dp[i-2].
            if (i > 1)
                pick += dp[i - 2];
            
            // The non-pick option is to use the maximum sum from the previous element.
            int nonPick = dp[i - 1];

            // Store the maximum of the two options in the dp array for the current index.
            dp[i] = Math.max(pick, nonPick);
        }

        // The final element of the dp array contains the maximum possible sum.
        return dp[n - 1];
    }


    // space optimisation
    static int solve(int n, int[] arr) {
        // Initialize variables to keep track of the maximum sums at the current and previous positions.
        int prev = arr[0];
        int prev2 = 0;

        // Iterate through the array starting from the second element.
        for (int i = 1; i < n; i++) {
            // Calculate the maximum sum by either picking the current element or not picking it.
            int pick = arr[i];

            // If there are at least two elements before the current element, add the value from prev2.
            if (i > 1)
                pick += prev2;

            // The non-pick option is to use the maximum sum from the previous position.
            int nonPick = prev;

            // Calculate the maximum sum for the current position and update prev and prev2.
            int cur_i = Math.max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }

        // The 'prev' variable now holds the maximum possible sum.
        return prev;
    }

    public static int rob(int[] nums) {
        int[] dp = new int[nums.length + 1];
        Arrays.fill(dp, -1);
        return solve(nums.length - 1, nums);
    }
}
