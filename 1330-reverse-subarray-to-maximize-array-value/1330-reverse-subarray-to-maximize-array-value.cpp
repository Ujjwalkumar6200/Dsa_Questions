class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();

        int initial = 0;

        for (int i = 0; i < n - 1; i++) {
            initial += abs(nums[i] - nums[i + 1]);
        }

        int gain = 0;

        // Reverse subarray [0 ... j]
        for (int j = 1; j < n; j++) {
            gain = max(
                gain,
                abs(nums[0] - nums[j]) -
                abs(nums[j - 1] - nums[j])
            );
        }

        // Reverse subarray [i ... n-1]
        for (int i = 0; i < n - 1; i++) {
            gain = max(
                gain,
                abs(nums[n - 1] - nums[i]) -
                abs(nums[i] - nums[i + 1])
            );
        }

        // Reverse a middle subarray [i ... j]
        int mx = INT_MIN;
        int mn = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];

            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));

            gain = max(gain, 2 * (mx - mn));
        }

        return initial + gain;
    }
};