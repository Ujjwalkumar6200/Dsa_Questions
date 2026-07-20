class Solution {
private:
      int n;
      int m;
public:

    void dfs(int row, int col,vector<vector<char>>& grid,int delrow[], int delcol[]){
            if (row < 0 || col < 0 || col >= n || row >= m || grid[row][col] == '0') return;
            grid[row][col] = '0';
            for(int i =0;i<4;i++){
                int nr = row + delrow[i];
                int nc = col+delcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'){
                    dfs(nr,nc,grid,delrow,delcol);
                }
            }
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,1,0,-1};
        int islands = 0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid,delrow,delcol);
                }
            }
        } return islands;
    }
};