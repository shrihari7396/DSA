package union.stones;

import java.util.*;

class UnionBySize {
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();

    // Constructor to initialize parent and size
    public UnionBySize(int n) {
        for (int i = 0; i <= n; i++) {
            parent.add(i);
            size.add(1);
        }
    }

    // Finds ultimate parent with path compression
    int findUParent(int node) {
        if (node == parent.get(node)) {
            return node;
        }
        int uParent = findUParent(parent.get(node));
        parent.set(node, uParent);
        return uParent;
    }

    // Unites two components using size heuristic
    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) return;

        if (size.get(pu) < size.get(pv)) {
            parent.set(pu, pv);
            size.set(pv, size.get(pv) + size.get(pu));
        } else {
            parent.set(pv, pu);
            size.set(pu, size.get(pu) + size.get(pv));
        }
    }
}

 
class Solution {
    public int removeStones(int[][] stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(int[] it : stones) {
            maxRow = Integer.max(maxRow, it[0]);
            maxCol = Integer.max(maxCol, it[1]);
        }

        UnionBySize ds = new UnionBySize(maxCol+maxRow+1);
        Map<Integer, Integer> map = new HashMap<>();
        for(int[] it : stones) {
            int nodeRow = it[0];
            int nodeCol = maxRow + it[1] + 1;

            ds.unionBySize(nodeRow, nodeCol);
            map.put(nodeRow, 1);
            map.put(nodeCol, 1);
        }
        int cnt = 0;
        for(Map.Entry<Integer, Integer> m : map.entrySet()) {
            int key = m.getKey();
            if(ds.findUParent(key) == key) cnt++;
        }

        return stones.length-cnt;
    }
}


public class Stones {
    public static void main(String[] args) {
        // Solution sol = new Solution();
    }
}
