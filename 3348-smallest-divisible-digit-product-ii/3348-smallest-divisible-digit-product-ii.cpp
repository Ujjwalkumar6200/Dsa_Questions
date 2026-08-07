class Solution {
public:
    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        long long x = t;

        while (x % 2 == 0) x /= 2, req2++;
        while (x % 3 == 0) x /= 3, req3++;
        while (x % 5 == 0) x /= 5, req5++;
        while (x % 7 == 0) x /= 7, req7++;

        if (x > 1) return "-1";

        const int INF = 1e9;
        int dp[60][40];

        for (auto &row : dp)
            fill(row, row + 40, INF);

        dp[0][0] = 0;

        int trans[][2] = {
            {1,0}, {0,1}, {2,0},
            {1,1}, {3,0}, {0,2}
        };

        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 40; j++) {
                if (dp[i][j] == INF) continue;

                for (auto &v : trans) {
                    int ni = min(59, i + v[0]);
                    int nj = min(39, j + v[1]);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
                }
            }
        }

        for (int i = 59; i >= 0; i--) {
            for (int j = 39; j >= 0; j--) {
                if (i < 59) dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                if (j < 39) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }

        int f2[] = {0,0,1,0,2,0,1,0,3,0};
        int f3[] = {0,0,0,1,0,0,1,0,0,2};
        int f5[] = {0,0,0,0,0,1,0,0,0,0};
        int f7[] = {0,0,0,0,0,0,0,1,0,0};

        int n = num.size();
        int firstZero = n;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        // Check num itself
        if (firstZero == n) {
            int a = req2, b = req3, c = req5, d = req7;

            for (char ch : num) {
                int x = ch - '0';
                a = max(0, a - f2[x]);
                b = max(0, b - f3[x]);
                c = max(0, c - f5[x]);
                d = max(0, d - f7[x]);
            }

            if (a == 0 && b == 0 && c == 0 && d == 0)
                return num;
        }

        int limit = min(n - 1, firstZero);
        int p2 = 0, p3 = 0, p5 = 0, p7 = 0;

        for (int i = 0; i < limit; i++) {
            int d = num[i] - '0';
            p2 += f2[d];
            p3 += f3[d];
            p5 += f5[d];
            p7 += f7[d];
        }

        // Try to keep the same length
        for (int i = limit; i >= 0; i--) {
            for (int d = num[i] - '0' + 1; d <= 9; d++) {

                int r2 = max(0, req2 - p2 - f2[d]);
                int r3 = max(0, req3 - p3 - f3[d]);
                int r5 = max(0, req5 - p5 - f5[d]);
                int r7 = max(0, req7 - p7 - f7[d]);

                int len = n - i - 1;

                if (r5 + r7 + dp[r2][r3] <= len) {
                    string ans = num.substr(0, i) + char('0' + d);

                    for (int pos = 0; pos < len; pos++) {
                        for (int x = 1; x <= 9; x++) {
                            int nr2 = max(0, r2 - f2[x]);
                            int nr3 = max(0, r3 - f3[x]);
                            int nr5 = max(0, r5 - f5[x]);
                            int nr7 = max(0, r7 - f7[x]);

                            if (nr5 + nr7 + dp[nr2][nr3] <= len - pos - 1) {
                                ans += char('0' + x);
                                r2 = nr2;
                                r3 = nr3;
                                r5 = nr5;
                                r7 = nr7;
                                break;
                            }
                        }
                    }

                    return ans;
                }
            }

            if (i > 0) {
                int d = num[i - 1] - '0';
                p2 -= f2[d];
                p3 -= f3[d];
                p5 -= f5[d];
                p7 -= f7[d];
            }
        }

        // Need a longer number
        int minLen = req5 + req7 + dp[req2][req3];
        int len = max(n + 1, minLen);

        string ans;
        int r2 = req2, r3 = req3, r5 = req5, r7 = req7;

        for (int pos = 0; pos < len; pos++) {
            for (int d = 1; d <= 9; d++) {
                int nr2 = max(0, r2 - f2[d]);
                int nr3 = max(0, r3 - f3[d]);
                int nr5 = max(0, r5 - f5[d]);
                int nr7 = max(0, r7 - f7[d]);

                if (nr5 + nr7 + dp[nr2][nr3] <= len - pos - 1) {
                    ans += char('0' + d);
                    r2 = nr2;
                    r3 = nr3;
                    r5 = nr5;
                    r7 = nr7;
                    break;
                }
            }
        }

        return ans;
    }
};