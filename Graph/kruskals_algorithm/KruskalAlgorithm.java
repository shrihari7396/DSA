package kruskals_algorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

// Disjoint Set Union by Size with Path Compression
class UnionBySize {
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();

    public UnionBySize(int n) {
        for (int i = 0; i <= n; i++) {
            parent.add(i);
            size.add(1);
        }
    }

    int findUParent(int node) {
        if (node == parent.get(node)) {
            return node;
        }
        int uParent = findUParent(parent.get(node));
        parent.set(node, uParent); // path compression
        return uParent;
    }

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

// Generic Pair class
class Pair<T, U> {
    public T first;
    public U second;

    Pair() {}

    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
}

// Main class for Kruskal's Algorithm
public class KruskalAlgorithm {

    // Kruskal's algorithm implementation
    private static int kruskalAlgorithmImplementation(List<Pair<Integer, Pair<Integer, Integer>>> edges, int numNodes) {
        int mstWeight = 0;

        UnionBySize ds = new UnionBySize(numNodes);

        for (Pair<Integer, Pair<Integer, Integer>> edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            if (ds.findUParent(u) != ds.findUParent(v)) {
                mstWeight += w;
                ds.unionBySize(u, v);
            }
        }

        return mstWeight;
    }

    public static void main(String[] args) {

        List<Pair<Integer, Pair<Integer, Integer>>> edges = new ArrayList<>();

        // Add edges: new Pair<>(weight, new Pair<>(u, v))
        edges.add(new Pair<>(4, new Pair<>(0, 1)));
        edges.add(new Pair<>(1, new Pair<>(2, 3)));
        edges.add(new Pair<>(7, new Pair<>(3, 4)));
        edges.add(new Pair<>(2, new Pair<>(1, 4)));
        edges.add(new Pair<>(6, new Pair<>(0, 3)));
        edges.add(new Pair<>(3, new Pair<>(2, 5)));
        edges.add(new Pair<>(5, new Pair<>(1, 5)));
        edges.add(new Pair<>(9, new Pair<>(4, 5)));
        edges.add(new Pair<>(8, new Pair<>(0, 2)));
        edges.add(new Pair<>(10, new Pair<>(3, 5)));

        // Sort edges by weight (ascending)
        Collections.sort(edges, new Comparator<Pair<Integer, Pair<Integer, Integer>>>() {
            @Override
            public int compare(Pair<Integer, Pair<Integer, Integer>> o1, Pair<Integer, Pair<Integer, Integer>> o2) {
                return Integer.compare(o1.first, o2.first);
            }
        });

        // Find number of nodes (max index + 1)
        int numNodes = 0;
        for (Pair<Integer, Pair<Integer, Integer>> edge : edges) {
            numNodes = Math.max(numNodes, Math.max(edge.second.first, edge.second.second));
        }

        // Compute MST weight
        int result = kruskalAlgorithmImplementation(edges, numNodes);
        System.out.println("Weight of the Minimum Spanning Tree is: " + result);
    }
}
