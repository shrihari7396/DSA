package union.implementation;

import java.util.ArrayList;
import java.util.List;

/*
 *
 * A) Finding Parent
 * B) Union 
 *  a) rank 
 *  b) size 
 * 1) Ultimate parents of u and v are pu and pv
 * 2) Find rank of the ultimate pu and pv
 * 3) Connect smaller ranks to larger ranks
 */

class DisjointSetByRank {
    List<Integer> rank = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();

    public DisjointSetByRank(int n) {
        for(int i=0;i<=n;i++) {
            rank.add(0);
            parent.add(i);
        }
    }

    int findUParent(int node) {
        if(node == parent.get(node)) {
            return node;
        }

        int UParent = findUParent(parent.get(node));
        parent.set(node, UParent);

        return parent.get(node);
    }

    void unionByRank(int u, int  v) {
        int ulpU = findUParent(u);
        int ulpV = findUParent(v);
        if(ulpU == ulpV) return;

        if(rank.get(ulpU) < rank.get(ulpV)) {
            parent.set(ulpU, ulpV);
        } else if(rank.get(ulpV) < rank.get(ulpU)) {
            parent.set(ulpV, ulpU);
        } else {
            parent.set(ulpV, ulpU);
            rank.set(ulpU, rank.get(ulpU)+1);
        }
    }
}

class unionByRankMine {
    List<Integer> parent = new ArrayList<>();
    List<Integer> rank = new ArrayList<>();
    unionByRankMine(int n) {
        for(int i = 0; i < n; i++) {
            rank.add(0);
            parent.add(i);
        }
    }

    int findUParent(int node) {
        if(node == parent.get(node)) return node;

        int UParent = findUParent(parent.get(node));
        parent.set(node, UParent);

        return parent.get(node);
    }

    void unionByRank(int u, int v) {
        int UParent = findUParent(u);
        int VParent = findUParent(v);

        if(rank.get(UParent) < rank.get(VParent)) {
            parent.set(UParent, VParent);
        } else if(rank.get(UParent) > rank.get(VParent)) {
            parent.set(VParent, UParent);
        } else {
            parent.set(UParent, VParent);
            rank.set(VParent, rank.get(UParent)+1);
        }
    }
}


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



public class UltimateParents {
    public static void main(String[] args) {
        DisjointSetByRank dj = new DisjointSetByRank(12);
        dj.unionByRank(2, 3);
        dj.unionByRank(1, 3);
        dj.unionByRank(6, 3);
        dj.unionByRank(11, 3);
        dj.unionByRank(10, 3);
        dj.unionByRank(6, 3);
        dj.unionByRank(2, 1);
        dj.unionByRank(2, 5);
        dj.unionByRank(7, 3);
        dj.unionByRank(7, 3);
        dj.unionByRank(2, 6);
        
        if(dj.findUParent(5)==dj.findUParent(2)) {
            System.out.println("Yes");
        } else {
            System.out.println("NO");
        }
    }
}

