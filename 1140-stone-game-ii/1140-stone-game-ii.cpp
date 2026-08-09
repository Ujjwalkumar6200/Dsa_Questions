class Solution {
public:
    int stoneGameII(vector<int>&A) {
        int n=A.size();
        vector dp(n+1,vector(2*n+1,vector(2,0)));
        for(int i=n-1;~i;--i){
            for(int m=n*2;m>0;--m){
                int sum=0,mini=1e9,maxi=-1e9;
                for(int x=1;x<=2*m&&i+x-1<n;++x){
                    sum+=A[i+x-1];
                    maxi=max(maxi,sum+dp[i+x][max(m,x)][1]);
                    mini=min(mini,dp[i+x][max(m,x)][0]);
                }
                dp[i][m][0]=maxi,dp[i][m][1]=mini;
            }
        }
        return dp[0][1][0];
    }
};