class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<pair<int,int>> adj[n];  //{{},{}}
            for(auto it : flights){
                int u = it[0];
                int v = it[1];
                int weight = it[2];
                adj[u].push_back({v,weight});
            }
            // graph is created
            queue<pair<int,pair<int,int>>> q;
            //{stops,{node,distance}}
            vector<int>dist(n,1e9);
            dist[src]=0;
            q.push({0,{src,0}});

            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int stops = it.first;
                int node = it.second.first;
                int distance = it.second.second;

                if(stops>k) continue;

                for(auto it: adj[node]){
                    int adjnode = it.first;
                    int edw = it.second;

                    if(edw+distance<dist[adjnode]&& stops<=k){
                        dist[adjnode] = edw+distance;
                        q.push({stops+1,{adjnode,edw+distance}});
                    }
                } 
            } if(dist[dst]==1e9) return -1;
            return dist[dst];

    }
};