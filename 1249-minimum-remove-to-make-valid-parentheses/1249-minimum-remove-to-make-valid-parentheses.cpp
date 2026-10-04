class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.length();
        string news = "";

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                cnt++;
                news += s[i];
            }

            else if (s[i] == ')') {

                if (cnt > 0) {
                    cnt--;
                    news += s[i];
                }
            }

            else {
                news += s[i];
            }
        }

        // Remove extra '(' from right to left
        for (int i = news.length() - 1; i >= 0 && cnt > 0; i--) {

            if (news[i] == '(') {
                news.erase(i, 1);
                cnt--;
            }
        }

        return news;
    }
};