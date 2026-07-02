class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];
        dq.push_front({0,0});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!dq.empty()) {
            auto [r,c] = dq.front();
            dq.pop_front();

            for(int k=0;k<4;k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr<0 || nr>=m || nc<0 || nc>=n)
                    continue;

                int wt = grid[nr][nc];

                if(dist[r][c] + wt < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + wt;

                    if(wt == 0)
                        dq.push_front({nr,nc});
                    else
                        dq.push_back({nr,nc});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};