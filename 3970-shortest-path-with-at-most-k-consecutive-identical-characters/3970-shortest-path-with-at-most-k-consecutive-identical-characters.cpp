class Solution {
public:
    
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<vector<int>>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,0,labels[0] - 'a', 1});
        int ans = INT_MAX;
        dist[0][1] = 0;

        while(!pq.empty())
        {
            int d = pq.top()[0];
            int node = pq.top()[1];
            int labelVal = pq.top()[2];
            int usedK = pq.top()[3];
            pq.pop();

            if(node == n-1)
            {
                ans = min(ans, d);
            }
            if(dist[node][usedK] < d) continue;
        

            for(int i = 0; i < adj[node].size(); i++)
            {
                int newNode = adj[node][i][0];
                int w = adj[node][i][1];
                int newLabel = labels[newNode] - 'a';
                int newK = 1;
                
                if(newLabel == labelVal) newK = usedK + 1;
                if(newK > k) continue;
                if(dist[newNode][newK] > d + w)
                {
                    pq.push({d + w, newNode, newLabel, newK});
                    dist[newNode][newK] = d + w;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};