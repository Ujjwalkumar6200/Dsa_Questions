class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        if (k == 1) {
            unordered_map<int, int> mp;

            for (int x : nums)
                mp[x]++;

            int ans = -1;

            for (auto &[x, freq] : mp) {
                if (freq == 1)
                    ans = max(ans, x);
            }

            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int first = nums[0];
        int last = nums[n - 1];

        int cntFirst = 0;
        int cntLast = 0;

        for (int x : nums) {
            if (x == first)
                cntFirst++;

            if (x == last)
                cntLast++;
        }

        int ans = -1;

        if (cntFirst == 1)
            ans = max(ans, first);

        if (cntLast == 1)
            ans = max(ans, last);

        return ans;
    }
};