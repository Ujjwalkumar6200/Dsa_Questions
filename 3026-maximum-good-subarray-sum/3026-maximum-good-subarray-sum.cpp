class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> mpp;

        long long sum = 0;
        long long ans = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            long long target1 = nums[i] - k;
            long long target2 = nums[i] + k;

            if(mpp.find(target1) != mpp.end()) {
                ans = max(ans, sum - mpp[target1]);
            }

            if(mpp.find(target2) != mpp.end()) {
                ans = max(ans, sum - mpp[target2]);
            }

            long long before = sum - nums[i];

            if(mpp.find(nums[i]) == mpp.end()) {
                mpp[nums[i]] = before;
            }
            else {
                mpp[nums[i]] = min(mpp[nums[i]], before);
            }
        }

        return ans == LLONG_MIN ? 0 : ans;
    }
};