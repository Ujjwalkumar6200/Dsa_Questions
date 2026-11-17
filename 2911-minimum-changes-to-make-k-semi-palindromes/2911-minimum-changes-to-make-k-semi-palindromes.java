class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();
        final int INF = 1_000_000_000;
        List<List<Integer>> divs = new ArrayList<>();
        for (int i = 0; i <= n; i++) divs.add(new ArrayList<>());
        for (int d = 1; d <= n; d++)
            for (int len = 2 * d; len <= n; len += d) divs.get(len).add(d);

        int[][] cost = new int[n][n];
        for (int[] row : cost) Arrays.fill(row, INF);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d : divs.get(len)) {
                    int m = len / d, cnt = 0;
                    for (int r = 0; r < d; r++) {
                        for (int lo = r, hi = r + (m - 1) * d; lo < hi; lo += d, hi -= d) {
                            if (s.charAt(i + lo) != s.charAt(i + hi)) cnt++;
                        }
                    }
                    best = Math.min(best, cnt);
                }
                cost[i][j] = best;
            }
        }

        int[][] dp = new int[n + 1][k + 1];
        for (int[] row : dp) Arrays.fill(row, INF);
        dp[0][0] = 0;
        for (int c = 1; c <= k; c++) {
            for (int p = 2 * c; p <= n; p++) {
                for (int q = 2 * (c - 1); q <= p - 2; q++) {
                    if (dp[q][c - 1] < INF) {
                        dp[p][c] = Math.min(dp[p][c], dp[q][c - 1] + cost[q][p - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
}