class Solution {
public:
    vector<string> solve(int index, string &s,
                         unordered_set<string> &st,
                         vector<vector<string>> &dp,
                         vector<bool> &vis) {

        if (index == s.size())
            return {""};

        if (vis[index])
            return dp[index];

        vis[index] = true;

        vector<string> ans;
        string word = "";

        for (int end = index; end < s.size(); end++) {

            word += s[end];

            if (st.count(word)) {

                vector<string> temp = solve(end + 1, s, st, dp, vis);

                for (string x : temp) {

                    if (x == "")
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + x);
                }
            }
        }

        return dp[index] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<vector<string>> dp(s.size());
        vector<bool> vis(s.size(), false);

        return solve(0, s, st, dp, vis);
    }
};