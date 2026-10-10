class Solution {
public:
    bool is_Possible(int m, int n, int k, vector<vector<int>>& dp) {
        int minR = INT_MAX, maxR = INT_MIN;
        int minC = INT_MAX, maxC = INT_MIN;
        bool found = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] >= k) {          
                    found = true;
                    minR = min(minR, i); maxR = max(maxR, i);
                    minC = min(minC, j); maxC = max(maxC, j);
                }
            }
        }

        if (!found) return false;
        return (maxR - minR >= k) || (maxC - minC >= k);
    }

    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;

        // First column
        for (int i = 0; i < m; i++) {
            dp[i][0] = mat[i][0];
            maxSide = max(maxSide, dp[i][0]);
        }

        // First row
        for (int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
            maxSide = max(maxSide, dp[0][j]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;   
                maxSide = max(maxSide, dp[i][j]);
            }
        }

        for (int i = maxSide; i > 0; i--) {
            if (is_Possible(m, n, i, dp)) return i * i;                            // FIX 3
        }
        return 0;
    }
};