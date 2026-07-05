class Solution {
public:

    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int take = nums[ind] + f(ind-2,nums,dp) ;
        int nottake= 0 + f(ind-1,nums,dp);
        return dp[ind]= max(take,nottake);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return f(nums.size()-1,nums,dp);
    }
};