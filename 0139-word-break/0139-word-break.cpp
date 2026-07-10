class Solution {
public:

    bool solve(int index,string & s, unordered_set<string>&st,vector<int>&dp){
        if(index==s.length()) return true;

        string word = "";
        if(dp[index]!=-1) return dp[index];
        for(int i =index;i<s.length();i++){
            word+=s[i];
            if(st.count(word)){
                if(solve(i+1,s,st,dp))
                return true;
            }
        } return dp[index]=false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};