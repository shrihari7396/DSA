
import java.util.Arrays;

public class HouseRobber {
    public static void main(String[] args) {
        Solution s=new  Solution();
        System.out.println(s);
        
    }   
} 

class Solution {

    private int solve(int i, int[] nums, int[] dp) {
        if (i < 0) {
            return 0;
        }
        if (i == 0) {
            return nums[0];
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int take = nums[i] + solve(i - 2, nums, dp);
        int notTake = solve(i - 1, nums, dp);

        return dp[i] = Math.max(take, notTake);
    }
    

    private int solve(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
    
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
    
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        }
    
        return dp[n - 1];
    }

    // space optimisation
    private int solve1(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
    
        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
    
        for (int i = 2; i < n; i++) {
            int curr = Math.max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
    
        return prev1;
    }
    
    

    public int rob(int[] nums) {
        int[] dp = new int[nums.length + 1];
        Arrays.fill(dp, -1);
        return solve(nums.length - 1, nums, dp);
    }
}
