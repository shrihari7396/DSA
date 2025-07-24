import java.util.Arrays;

class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int maxi = nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++) {
            maxi = Integer.max(maxi, nums[i+1]-nums[i]);
        }

        return maxi < 0 ? -1*maxi : maxi;
    }

    public static void main(String[] args) {
        System.out.println("Each ");
    }
}