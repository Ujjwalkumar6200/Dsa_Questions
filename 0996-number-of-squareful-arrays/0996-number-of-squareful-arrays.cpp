class Solution {
public:
    int n;
    int ans = 0;

    bool isSquare(int x) {
        int root = sqrt(x);
        return root * root == x;
    }

    void helper(vector<int>& nums, vector<int>& used, int ind, int prev) {

        if (ind == n) {
            ans++;
            return;
        }

        for (int i = 0; i < n; i++) {

            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
                
            if (ind > 0) {
                if (!isSquare(nums[prev] + nums[i]))
                    continue;
            }

            used[i] = 1;

            helper(nums, used, ind + 1, i);

            used[i] = 0;
        }
    }

    int numSquarefulPerms(vector<int>& nums) {

        n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> used(n, 0);

        helper(nums, used, 0, -1);

        return ans;
    }
};