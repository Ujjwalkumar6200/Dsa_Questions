class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        // distance,{row,col};
        queue<pair<int,pair<int,int>>>  q;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i =-1;i<=1;i++){
                for(int j =-1;j<=1;j++){
                    int newr = row+i;
                    int newc = col+j;
                    if(newr>=0 && newc>=0 && newr<n && newc<n && grid[newr][newc]==0 && dis+1<distance[newr][newc]){
                        distance[newr][newc] = dis+1;
                        if(newr==n-1 && newc==n-1) return distance[newr][newc];
                        q.push({distance[newr][newc],{newr,newc}});
                    }
                }
            } 
        } return -1;
    }
};