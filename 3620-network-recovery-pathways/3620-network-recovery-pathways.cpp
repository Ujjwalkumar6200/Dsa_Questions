class Solution {

    bool check(int mid,
               vector<vector<pair<int,int>>>& adj,
               vector<int>& topo,
               vector<bool>& online,
               long long k,
               int n)
    {
        const long long INF = 1e18;

        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {

            if (dist[u] == INF)
                continue;

            // Intermediate node must be online
            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto &it : adj[u]) {

                int v = it.first;
                int wt = it.second;

                // Minimum edge should be at least mid
                if (wt < mid)
                    continue;

                // Intermediate node must be online
                if (v != n - 1 && !online[v])
                    continue;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        return dist[n - 1] <= k;
    }

public:

    // Given DAG
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        int mxEdge = 0;

        // Build graph
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            indegree[v]++;

            mxEdge = max(mxEdge, w);
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto &it : adj[node]) {

                indegree[it.first]--;

                if (indegree[it.first] == 0)
                    q.push(it.first);
            }
        }

        // Binary Search
        int low = 0;
        int high = mxEdge;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, adj, topo, online, k, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};