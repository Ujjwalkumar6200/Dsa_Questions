class Solution {
public:
    using T = pair<pair<int,int>, int>;
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<T> q;  //{{row,col}time};
        for(int  i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }

            }
        }

        int maxT =0;
        int delr[]={+1,0,-1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            maxT = max(maxT,time);

            for(int i =0;i<4;i++){
                int newr = row+delr[i];
                int newc = col+delc[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m && vis[newr][newc]!=2 && grid[newr][newc]==1){
                    vis[newr][newc]=2;
                    q.push({{newr,newc},time+1});
                }
            }
            

        }  for(int i =0;i<n;i++){
                 for(int j =0;j<m;j++){
                if(vis[i][j]!=2&&grid[i][j]==1) return -1;
            }
        }
        
        return maxT;

    }
};