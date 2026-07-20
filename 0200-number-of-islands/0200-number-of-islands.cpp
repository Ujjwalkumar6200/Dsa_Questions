class Solution {
 
 private:

 int n;
 int m;

 void dfs(int row,int col , const vector<vector<char>>& grid,vector<vector<int>>& visited){
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,1,0,-1};

    for(int i =0;i<4;i++){
        int nr = row + delrow[i];
        int nc = col + delcol[i];
        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == '1' && visited[nr][nc]==1){
            visited[nr][nc] = 0;
            dfs(nr,nc,grid,visited);
        }
    }
 }   
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,1));
        int islands = 0;

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==1){
                    visited[i][j]=0;
                    islands++;
                    dfs(i,j,grid,visited);
                }
            }
        } return islands;
    }
};