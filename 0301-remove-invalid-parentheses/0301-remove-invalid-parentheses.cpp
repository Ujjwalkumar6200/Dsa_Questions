class Solution {
public:

    void dfs(string &s, int index,
             int leftRemove, int rightRemove,
             int leftCount, int rightCount,
             string &current, vector<string> &ans) {

        if(index == s.length()) {

            if(leftRemove == 0 && rightRemove == 0) {
                ans.push_back(current);
            }

            return;
        }

        // Remove current '('
        if(s[index] == '(' && leftRemove > 0) {

            dfs(s, index + 1,
                leftRemove - 1, rightRemove,
                leftCount, rightCount,
                current, ans);
        }

        // Remove current ')'
        if(s[index] == ')' && rightRemove > 0) {

            dfs(s, index + 1,
                leftRemove, rightRemove - 1,
                leftCount, rightCount,
                current, ans);
        }

        // Keep current character
        if(s[index] != '(' && s[index] != ')') {

            current.push_back(s[index]);

            dfs(s, index + 1,
                leftRemove, rightRemove,
                leftCount, rightCount,
                current, ans);

            current.pop_back();
        }

        // Keep '('
        else if(s[index] == '(') {

            current.push_back('(');

            dfs(s, index + 1,
                leftRemove, rightRemove,
                leftCount + 1, rightCount,
                current, ans);

            current.pop_back();
        }

        // Keep ')' only if valid
        else if(s[index] == ')' && leftCount > rightCount) {

            current.push_back(')');

            dfs(s, index + 1,
                leftRemove, rightRemove,
                leftCount, rightCount + 1,
                current, ans);

            current.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate minimum removals
        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                leftRemove++;
            }
            else if(s[i] == ')') {

                if(leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        vector<string> ans;
        string current = "";

        dfs(s, 0,
            leftRemove, rightRemove,
            0, 0,
            current, ans);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};