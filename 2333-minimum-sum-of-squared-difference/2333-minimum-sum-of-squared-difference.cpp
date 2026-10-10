
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        long long sum = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            maxi = max(maxi, diff[i]);
        }

        if (sum <= k) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int limit = low;
        long long used = 0;

        for (int d : diff) {
            if (d > limit) {
                used += d - limit;
            }
        }

        long long remaining = k - used;
        long long ans = 0;

        for (int d : diff) {
            int x = min(d, limit);

            if (x == limit && remaining > 0) {
                x--;
                remaining--;
            }

            ans += 1LL * x * x;
        }

        return ans;
    }
};
