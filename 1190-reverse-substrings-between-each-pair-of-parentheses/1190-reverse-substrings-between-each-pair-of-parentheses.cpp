class Solution {
public:
    string reverseParentheses(string s) {
        string rev = "";
        vector<int> index;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                index.push_back(rev.length());
            }
            else if(s[i] == ')') {
                reverse(rev.begin() + index.back(), rev.end());
                index.pop_back();
            }
            else {
                rev += s[i];
            }
        }

        return rev;
    }
};