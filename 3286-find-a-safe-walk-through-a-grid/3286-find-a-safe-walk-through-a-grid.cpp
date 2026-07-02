class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // Lose health if starting cell is unsafe
        health -= grid[0][0];

        if (health <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<vector<int>> q;

        // {row, col, remainingHealth}
        q.push({0, 0, health});
        best[0][0] = health;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr[0];
            int col = curr[1];
            int currHealth = curr[2];

            // Reached destination
            if (row == m - 1 && col == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = row + drow[k];
                int nc = col + dcol[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int newHealth = currHealth - grid[nr][nc];

                    // Health must remain positive
                    if (newHealth <= 0)
                        continue;

                    // Visit only if we arrive with more health
                    if (newHealth > best[nr][nc]) {
                        best[nr][nc] = newHealth;
                        q.push({nr, nc, newHealth});
                    }
                }
            }
        }

        return false;
    }
};