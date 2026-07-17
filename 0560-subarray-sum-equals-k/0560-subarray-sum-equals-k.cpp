class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCounts;
        
        // Base case: A prefix sum of 0 has occurred exactly 1 time (an empty subarray)
        prefixCounts[0] = 1;
        
        int currentSum = 0;
        int totalSubarrays = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            // If (currentSum - k) exists in the map, add its frequency to our total
            int target = currentSum - k;
            if (prefixCounts.count(target)) {
                totalSubarrays += prefixCounts[target];
            }
            
            // Record the current prefix sum in the map for future indices to use
            prefixCounts[currentSum]++;
        }
        
        return totalSubarrays;
    }
};