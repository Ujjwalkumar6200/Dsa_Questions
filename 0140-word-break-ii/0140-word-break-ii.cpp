class Solution {
public:
    vector<string> solve(int index, string &s,
                         unordered_set<string> &st) {

        if (index == s.size())
            return {""};

        vector<string> ans;

        string word = "";

        for (int end = index; end < s.size(); end++) {

            word += s[end];

            if (st.count(word)) {

                vector<string> temp = solve(end + 1, s, st);

                for (string x : temp) {

                    if (x == "")
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + x);
                }
            }
        }

        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        return solve(0, s, st);
    }
};