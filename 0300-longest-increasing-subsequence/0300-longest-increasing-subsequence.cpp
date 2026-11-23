class Solution {
public:
    int ans(int ind, vector<int>& nums, int prev, vector<vector<int>>& dp) {
        if(ind == nums.size()) {
            return 0;
        }

        if(dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        // Not Pick
        int not_pick = ans(ind + 1, nums, prev, dp);

        // Pick
        int pick = 0;
        if(prev == -1 || nums[ind] > nums[prev]) {
            pick = 1 + ans(ind + 1, nums, ind, dp);
        }

        return dp[ind][prev + 1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return ans(0, nums, -1, dp);
    }
};