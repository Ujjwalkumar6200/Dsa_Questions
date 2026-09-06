class Solution {
public:
    int solve(int i,int j,string&s,string&t,vector<vector<int>>&dp){
        if(j<0){
            return 1;
        }
        if(i<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int temp=0; 

        if(s[i]==t[j]){
            temp+=solve(i-1,j-1,s,t,dp);
        }
        temp+=solve(i-1,j,s,t,dp);
        
        return dp[i][j]=temp;
    }
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        if(n<m) return 0;
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};