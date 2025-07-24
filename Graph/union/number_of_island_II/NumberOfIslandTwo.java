package union.number_of_island_II;

import java.util.ArrayList;
import java.util.List;

class UnionBySize {
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();

    public UnionBySize(int n) {
        for(int i=0;i<n;i++) {
            size.add(1);
            parent.add(i);
        }
    }

    public int findUParent(int node) {
        if(node == parent.get(node)) {
            return node;
        }

        int ultimateParent = findUParent(parent.get(node));
        parent.set(node, ultimateParent);
        return ultimateParent;
    }

    public void union(int u, int v) {
        int uplU = findUParent(u);
        int uplV = findUParent(v);
        if(uplU == uplV) return;

        if(size.get(uplU) < size.get(uplV)) {
            size.set(uplU, size.get(uplV) + size.get(uplU));
            parent.set(uplU, uplV);
        } else {
            size.set(uplV, size.get(uplU) + size.get(uplV));
            parent.set(uplV, uplU);
        }
    }
}

class Solution {
    
    public List<Integer> findNumberOfConnectedComponentsForCurrentInsertion(int[] edges, int m, int n) {
        int totalEdges = m*n;
        UnionBySize ds = new UnionBySize(totalEdges);

        return null;
    } 
    
}

public class NumberOfIslandTwo {
    public static void main(String[] args) {
        
    }
}
