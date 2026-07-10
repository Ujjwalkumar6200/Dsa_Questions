class Solution {
public:

    bool wordBreak(string s, unordered_set<string>& st) {

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

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
             });

        unordered_set<string> st;
        vector<string> ans;

        for (auto &word : words) {

            if (word.empty()) continue;

            if (wordBreak(word, st))
                ans.push_back(word);

            st.insert(word);
        }

        return ans;
    }
};