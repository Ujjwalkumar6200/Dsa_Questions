class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(m+2,vector<int>(m+2));
        for(int i=m;i>=1;i--){
            for(int j =1;j<=m;j++){ 
                 if(i>j) continue;
                int mini = INT_MAX;
                for(int ind = i;ind<=j;ind++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini,cost);
                } dp[i][j]=mini;
            }
        }
        return dp[1][m];
    }
};