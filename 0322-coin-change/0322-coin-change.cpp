class Solution {
public:
    int returni (int ind,int amount,vector<int>& coins, vector<vector<int>> &dp){
         if(ind == 0){
            if(amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_Pick = returni(ind-1,amount,coins,dp);
        int pick = INT_MAX;
        if(coins[ind]<=amount){
            pick = 1+ min(returni(ind-1,amount-coins[ind],coins,dp),returni(ind,amount-coins[ind],coins,dp));
        }
        return dp[ind][amount]=min(pick,not_Pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = returni(coins.size()-1,amount,coins,dp);
         if(ans >= 1e9) return -1;

        return ans;
    }
};