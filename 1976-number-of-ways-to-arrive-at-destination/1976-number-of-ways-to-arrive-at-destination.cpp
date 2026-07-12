class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        //graph create
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            int u = it[0];
            int v= it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

                priority_queue<pair<long long,int>,
                        vector<pair<long long,int>>,
                        greater<pair<long long,int>>> pq;

            vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n,0);

            dist[0]=0;
            ways[0]=1;
            pq.push({0,0});

            while(!pq.empty()){

                auto it = pq.top();
                pq.pop();

                long long wgt = it.first;
                int node = it.second;

                if(wgt > dist[node]) continue;

                for(auto &it: adj[node]){

                    int adjn = it.first;
                    int edgeWt = it.second;

                    if(wgt + edgeWt < dist[adjn]){
                        dist[adjn] = wgt + edgeWt;
                        ways[adjn] = ways[node];
                        pq.push({dist[adjn], adjn});
                    }
                    else if(wgt + edgeWt == dist[adjn]){
                        ways[adjn] = (ways[adjn] + ways[node]) % mod;
                    }
                }
            }
         return ways[n-1] % mod;
    }
};