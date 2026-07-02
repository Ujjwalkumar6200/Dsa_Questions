class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        health -= grid[0][0];

        if(health<=0) return false;

        
        vector<vector<int>> best(n,vector<int>(m,INT_MIN));  
        queue<vector<int>> q;
        q.push({0,0,health});
        best[0][0] = health;

        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node[0];
            int c = node[1];
            int h = node[2];

            if( r == n-1 && c == m-1 ) return true;

            for(int k =0;k<4;k++){
                int nr = r+drow[k];
                int nc = c+dcol[k];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int newh = h-grid[nr][nc];
                if(newh<=0) continue;

                if(newh>best[nr][nc]){
                    q.push({nr,nc,newh});
                    best[nr][nc] = newh;
                }



            }

        } return false;

    }
};