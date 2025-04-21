
public class Stocks1DP {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int maxDiff = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(prices[i]-prices[j] > maxDiff) {
                    maxDiff=prices[i]-prices[j];
                }
            }
        }
        return maxDiff;
    }

    // Optimezed
    public int maxProfitOptimize(int[] prices) {
        int n = prices.length;
        int maxProfit=0;
        int mini=Integer.MAX_VALUE;;
        
        for(int i=0;i<n;i++) {
            maxProfit = Math.max(maxProfit, prices[i]-mini);
            mini = Math.min(mini, prices[i]);
        }
        return maxProfit;
    }
}