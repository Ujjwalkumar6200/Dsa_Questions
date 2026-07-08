class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 2; i >= 1; i--) {
            for (int j = i; j <= m - 2; j++) {

                int mini = INT_MAX;

                for (int ind = i; ind <= j; ind++) {

                    int cost = cuts[j + 1] - cuts[i - 1]
                             + dp[i][ind - 1]
                             + dp[ind + 1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][m - 2];
    }
};