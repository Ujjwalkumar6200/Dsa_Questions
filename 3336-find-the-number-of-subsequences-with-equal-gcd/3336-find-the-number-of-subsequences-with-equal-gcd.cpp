class Solution {
public:

    int MOD  = 1e9 + 7; 

    int helper(int idx,int gcd1, int gcd2, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if(idx==nums.size()){
            if(gcd1==gcd2 && gcd1>0){
                return  1;
            }
            return 0;
        }

        long long ans =0;

        if(dp[idx][gcd1][gcd2]!=-1) return dp[idx][gcd1][gcd2]; 
        int not_pick = helper(idx+1,gcd1,gcd2,nums,dp) % MOD;
        
        int new_gcd1 = (gcd1==0) ? nums[idx] : gcd(gcd1,nums[idx]);
        int pick1 =   helper(idx+1,new_gcd1,gcd2,nums,dp) % MOD;

        int new_gcd2 = (gcd2==0) ? nums[idx] : gcd(gcd2,nums[idx]);
        int pick2 =helper(idx+1,gcd1,new_gcd2,nums,dp) % MOD;
        
        ans += not_pick;
        ans += pick1;
        ans += pick2;

        return dp[idx][gcd1][gcd2] = ans % MOD;


    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
       vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(201, vector<int>(201, -1)));

        return helper(0,0,0,nums,dp);
    }
};