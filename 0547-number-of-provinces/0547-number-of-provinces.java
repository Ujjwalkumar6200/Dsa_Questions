class Solution {

    public void dfs(int node, ArrayList<ArrayList<Integer>> adj, int[] vis) {

        vis[node] = 1;

        for (var it : adj.get(node)) {
            if (vis[it] == 0) {
                dfs(it, adj, vis);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {

        int n = isConnected.length;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        // Create n empty lists
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Convert adjacency matrix → adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (isConnected[i][j] == 1) {
                    adj.get(i).add(j);
                }
            }
        }

        int[] vis = new int[n];

        int component = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i] == 0) {
                component++;
                dfs(i, adj, vis);
            }
        }

        return component;
    }
}