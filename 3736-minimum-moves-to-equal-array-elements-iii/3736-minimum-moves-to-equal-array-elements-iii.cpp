class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int arraysum = accumulate(nums.begin(),nums.end(),0);
        int ansSum = n*maxi;
        int ans = ansSum-arraysum;
        return ans;
    }
};