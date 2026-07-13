class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i,j},0});
                } 
            }
        }
        int maxT = 0;
        int  delr[] ={-1,0,+1,0};
        int  delc[] ={0,+1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            for(int i =0;i<4;i++){
                int newr = row+delr[i];
                int newc = col+delc[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]==1 && visited[newr][newc]!=2){
                    visited[newr][newc]=2;
                    q.push({{newr,newc},time+1});
                }
                maxT = max(maxT,time);
            }
            
        }for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return maxT;
       
    }
};