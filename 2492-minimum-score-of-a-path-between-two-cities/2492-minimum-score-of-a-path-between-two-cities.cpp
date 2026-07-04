class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int no = roads.size();
        int ans = INT_MAX;

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < no; i++) {
            int u = roads[i][0] - 1;
            int v = roads[i][1] - 1;
            int w = roads[i][2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            int node = q.front().first;
            q.pop();

            if (visited[node])
                continue;

            visited[node] = true;

            for (auto &it : graph[node]) {
                int nextNode = it.first;
                int weight = it.second;

                ans = min(ans, weight);

                if (!visited[nextNode]) {
                    q.push({nextNode, weight});
                }
            }
        }

        return ans;
    }
};