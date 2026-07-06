class Solution {
public:
    int returni (int ind,int amount,vector<int>& coins, vector<vector<int>> &dp){
         if(ind == 0){
            if(amount % coins[0] == 0)
                return 1;
            return 0;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_Pick = returni(ind-1,amount,coins,dp);
        int pick = 0;
        if(coins[ind]<=amount){
            pick = returni(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]= pick + not_Pick;
    }


    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return returni(coins.size()-1,amount,coins,dp);
         
    }
};