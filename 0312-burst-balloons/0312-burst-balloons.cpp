class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int m = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(m+2,vector<int>(m+2));
        for(int i=m;i>=1;i--){
            for(int j =1;j<=m;j++){ 
                 if(i>j) continue;
                int maxi = INT_MIN;
                for(int ind = i;ind<=j;ind++){
                    int cost = nums[i-1]*nums[ind] *nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(maxi,cost);
                } dp[i][j]=maxi;
            }
        }
        return dp[1][m];
    }
};