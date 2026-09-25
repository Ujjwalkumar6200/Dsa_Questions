class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int total = 0, res = 0;
        int mn = INT_MAX, mx = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];

            total += abs(a - b);

            res = max(res, abs(nums[0] - b) - abs(a - b));
            res = max(res, abs(nums[n - 1] - a) - abs(a - b));

            mn = min(mn, max(a, b));
            mx = max(mx, min(a, b));
        }

        return total + max(res, 2 * (mx - mn));
    }
};