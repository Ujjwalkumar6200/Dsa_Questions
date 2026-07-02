class Solution {
public:
    struct Node {
        int row;
        int col;
        int health;
    };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        // If starting cell is unsafe, lose 1 health
        health -= grid[0][0];

        if (health <= 0)
            return false;

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<Node> q;
        q.push({0, 0, health});

        best[0][0] = health;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            Node curr = q.front();
            q.pop();

            int r = curr.row;
            int c = curr.col;
            int h = curr.health;

            // Reached destination
            if (r == n - 1 && c == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {

                int nr = r + drow[k];
                int nc = c + dcol[k];

                // Boundary check
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newHealth = h - grid[nr][nc];

                // Health must remain positive
                if (newHealth <= 0)
                    continue;

                // Visit only if we reach with more health
                if (newHealth > best[nr][nc]) {

                    best[nr][nc] = newHealth;
                    q.push({nr, nc, newHealth});
                }
            }
        }

        return false;
    }
};