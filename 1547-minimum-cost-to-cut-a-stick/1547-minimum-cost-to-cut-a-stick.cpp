class Solution {
public:
    int costi(int i, int j, vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind = i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1] + costi(i,ind-1,cuts,dp)+ costi(ind+1,j,cuts,dp);
            mini = min(mini,cost);
        } return dp[i][j]=mini;
    }


    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));

        return costi(1,m-2,cuts,dp);
    }
};