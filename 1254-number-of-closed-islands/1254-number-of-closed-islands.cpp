class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int delrow[], int delcol[]) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        bool closed = true;

        for (int i = 0; i < 4; i++) {
            int delr = row + delrow[i];
            int delc = col + delcol[i];

            if (delr < 0 || delc < 0 || delr >= n || delc >= m) {
                closed = false;
                continue;
            }

            if (!vis[delr][delc] && grid[delr][delc] == 0) {
                if (!dfs(delr, delc, grid, vis, delrow, delcol)) {
                    closed = false;
                }
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int component = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    if (dfs(i, j, grid, vis, delrow, delcol)) {
                        component++;
                    }
                }
            }
        }

        return component;
    }
};