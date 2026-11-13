class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 1;

        while ((1 << m) <= n)
            m++;

        vector<int> g(n + 1, n), s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.back()] < nums[i]) {
                g[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }

        vector<vector<int>> p(m, vector<int>(n + 1, n));
        vector<vector<long long>> b(m, vector<long long>(n + 1, 0));
        vector<long long> a(n + 1, 0);

        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + nums[i];
            p[0][i] = g[i];
            b[0][i] = 1LL * nums[i] * (g[i] - i);
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int x = p[j - 1][i];

                p[j][i] = p[j - 1][x];
                b[j][i] = b[j - 1][i] + b[j - 1][x];
            }
        }

        auto f = [&](int l, int r) -> long long {
            long long v = 0;
            int x = l;

            for (int j = m - 1; j >= 0; j--) {
                if (p[j][x] <= r) {
                    v += b[j][x];
                    x = p[j][x];
                }
            }

            v += 1LL * nums[x] * (r - x + 1);

            return v - (a[r + 1] - a[l]);
        };

        long long z = 0;

        for (int r = 0; r < n; r++) {
            int l = 0, h = r;

            while (l < h) {
                int mid = l + (h - l) / 2;

                if (f(mid, r) <= k) {
                    h = mid;
                } else {
                    l = mid + 1;
                }
            }

            z += r - l + 1;
        }

        return z;
    }
};