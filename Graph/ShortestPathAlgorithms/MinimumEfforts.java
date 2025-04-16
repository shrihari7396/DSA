import java.util.*;

class Solution {
    private boolean check(int i, int j, int[][] nums) {
        return i >= 0 && i < nums.length && j >= 0 && j < nums[0].length;
    }

    private int helper(int[][] nums, int m, int n) {
        int[][] dist = new int[n][m];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        int[] x_inc = {0, 0, -1, 1};
        int[] y_inc = {1, -1, 0, 0};
        dist[0][0] = 0;
        pq.offer(new int[]{0, 0, 0}); // {effort, x, y}

        while (!pq.isEmpty()) {
            int[] it = pq.poll();
            int effort = it[0];
            int x = it[1];
            int y = it[2];

            if (x == n - 1 && y == m - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {
                int xnew = x + x_inc[i];
                int ynew = y + y_inc[i];

                if (check(xnew, ynew, nums)) {
                    int newEffort = Math.max(effort, Math.abs(nums[xnew][ynew] - nums[x][y]));
                    if (newEffort < dist[xnew][ynew]) {
                        dist[xnew][ynew] = newEffort;
                        pq.offer(new int[]{newEffort, xnew, ynew});
                    }
                }
            }
        }
        return -1;
    }

    public int minimumEffortPath(int[][] nums) {
        int n = nums.length;
        int m = nums[0].length;
        return helper(nums, m, n);
    }

    public static void main(String[] args) {
        // Example usage
        Solution sol = new Solution();
        int[][] nums = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
        System.out.println(sol.minimumEffortPath(nums));
    }
}

public class MinimumEfforts {
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}