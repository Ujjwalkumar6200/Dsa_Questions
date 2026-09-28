class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> mp;
        
        long long sum = 0;
        long long ans = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            long long x = nums[i] - k;
            long long y = nums[i] + k;

            if(mp.find(x) != mp.end()) {
                ans = max(ans, sum - mp[x]);
            }

            if(mp.find(y) != mp.end()) {
                ans = max(ans, sum - mp[y]);
            }

            long long before = sum - nums[i];

            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = before;
            } else {
                mp[nums[i]] = min(mp[nums[i]], before);
            }
        }

        return ans == LLONG_MIN ? 0 : ans;
    }
};