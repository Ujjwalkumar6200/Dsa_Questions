class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int p = m+n;
        if ((m+n)% 2 == 0){
            return false;
        }
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(p, false)));
        bool open = false;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == '('){
                    open = true;
                } else if (grid[i][j] == ')'){
                    open = false;
                }
                if (i == 0 && j == 0){
                    if (!open){
                        return false;
                    }
                    dp[i][j][1] = true;
                    continue;
                }
                if (i > 0){
                    for (int k=0; k<p; k++){
                        if (dp[i-1][j][k]){
                            if (open){
                                dp[i][j][k+1] = true;
                            } else {
                                if ((k-1) >= 0){
                                    dp[i][j][k-1] = true;
                                }
                            }
                        }
                    }
                }
                if (j > 0){
                    for (int k=0; k<p; k++){
                        if (dp[i][j-1][k]){
                            if (open){
                                dp[i][j][k+1] = true;
                            } else {
                                if ((k-1) >= 0){
                                    dp[i][j][k-1] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};