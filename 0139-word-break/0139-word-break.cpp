class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<bool>dp(s.size(),false);
        int n = s.length();
        dp[n]= true;
        for(int j =n-1;j>=0;j--){
            string word = "";
             for(int i =j;i<s.length();i++){
              word+=s[i];
                if(st.count(word)){
                    if(dp[i+1]){
                         dp[j]=true;
                         true;
                    }
                }
             }
        } return dp[0];
    }
};