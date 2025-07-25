import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int maxi = nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++) {
            maxi = Integer.max(maxi, nums[i+1]-nums[i]);
        }

        return maxi < 0 ? -1*maxi : maxi;
    }  

    public static void main(String[] args) {
        List<Thread> list = new ArrayList<>();
        for(int i = 0; i < 1000000; i++) {
            list.add(new Thread(new Shrihari()));
        }
        for(int i = 0; i < 1000000; i++) {
            list.get(i).start();
        }
        System.out.println("All Done!");
    }
}   

class Shrihari implements Runnable {
    @Override
    public void run() {
        for(int i = 0; i < 1000000; i++) {
            try {
                Thread.sleep(1000000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            System.out.println("Vivek" + i);
        }
    }
}