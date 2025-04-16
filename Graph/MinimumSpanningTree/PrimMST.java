import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Pair {
    int node;
    int distance;
    public Pair(int node, int distance) {
        this.node = node;
        this.distance = distance;
    }
}

public class PrimMST {

    int spanningTree(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> Integer.compare(x.distance, y.distance));
        int[] vis = new int[V];
        pq.add(new Pair(0, 0));
        int sum = 0;

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int wt = p.distance;
            int node = p.node;

            if (vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for (int i = 0; i < adj.get(node).size(); i++) {
                int adjNode = adj.get(node).get(i).get(0);
                int edw = adj.get(node).get(i).get(1);

                if (vis[adjNode] == 0) {
                    pq.add(new Pair(adjNode, edw));
                }
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        int V = 4;
        ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<>();

        // initialize graph
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // add undirected edges: u <-> v with weight w
        adj.get(0).add(new ArrayList<>(List.of(1, 2)));
        adj.get(0).add(new ArrayList<>(List.of(2, 3)));

        adj.get(1).add(new ArrayList<>(List.of(0, 2)));
        adj.get(1).add(new ArrayList<>(List.of(2, 1)));
        adj.get(1).add(new ArrayList<>(List.of(3, 1)));

        adj.get(2).add(new ArrayList<>(List.of(0, 3)));
        adj.get(2).add(new ArrayList<>(List.of(1, 1)));
        adj.get(2).add(new ArrayList<>(List.of(3, 4)));

        adj.get(3).add(new ArrayList<>(List.of(1, 1)));
        adj.get(3).add(new ArrayList<>(List.of(2, 4)));

        PrimMST obj = new PrimMST();
        int mstWeight = obj.spanningTree(V, adj);
        System.out.println("Total weight of MST: " + mstWeight);
    }
}
