class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[n] = true;

        for (int j = n - 1; j >= 0; j--) {

            string word = "";

            for (int i = j; i < n; i++) {

                word += s[i];

                if (st.count(word) && dp[i + 1]) {
                    dp[j] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};