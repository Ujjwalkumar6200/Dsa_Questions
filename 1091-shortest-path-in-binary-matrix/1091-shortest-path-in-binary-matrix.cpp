class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;
        
        pair<int,int> source = {0,0};
       
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        dist[source.first][source.second] = 1;
        q.push({1,{source.first,source.second}});
        int dr[] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i =-1;i<=1;i++){
                for(int j = -1; j<=1;j++){
                int newr = r+i;
                int newc = c+j;
                if(newr>=0 && newr<n && newc >=0 && newc<n && grid[newr][newc] == 0 && dis+1 < dist[newr][newc] ){
                    dist[newr][newc] = 1+dis;
                    if(newr==n-1&&newc==n-1) return dist[newr][newc];
                    q.push({1+dis,{newr,newc}});
                }
             }
           }
        } return -1;
    }
};