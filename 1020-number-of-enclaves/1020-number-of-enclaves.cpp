class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             int delrow[], int delcol[]) {

        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && ncol >= 0 &&
                nrow < n && ncol < m &&
                grid[nrow][ncol] == 1 &&
                !vis[nrow][ncol]) {

                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Traverse first and last row
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, vis, grid, delrow, delcol);

            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, vis, grid, delrow, delcol);
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, vis, grid, delrow, delcol);

            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, vis, grid, delrow, delcol);
        }

        int cnt = 0;

        // Count unvisited land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};