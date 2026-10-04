class Solution {
public:
    unordered_set<string> st;
    int longest_string = -1;

    void dfs(string &s, int index, string &current, int lcount, int rcount) {
        if (index == s.length()) {
            if (lcount == rcount) {
                int len = current.length();
                if (len > longest_string) {
                    st.clear();
                    longest_string = current.length();
                    st.insert(current);
                }
                else if(len == longest_string) {
                    st.insert(current);
                }
            }
        }
        else {
            char curr_char = s[index];
            if (curr_char == '(') {
                current += curr_char;
                dfs(s, index+1, current, lcount+1, rcount);
                current.pop_back();
                dfs(s, index+1, current, lcount, rcount);
            }
            else if(curr_char == ')') {
                dfs(s, index+1, current, lcount, rcount);
                if (lcount > rcount) {
                    current += curr_char;
                    dfs(s, index+1, current, lcount, rcount+1);
                    current.pop_back();
                }
            }
            else {
                current += curr_char;
                dfs(s, index+1, current, lcount, rcount);
                current.pop_back();
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        st.clear();
        string current = "";
        longest_string = -1;
        dfs(s, 0, current, 0, 0);
        return vector<string>(st.begin(), st.end());
    }
};