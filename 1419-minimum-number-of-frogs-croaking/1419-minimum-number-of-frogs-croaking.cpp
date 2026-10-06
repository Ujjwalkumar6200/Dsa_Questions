class Solution {
public:
    int minNumberOfFrogs(string s) {
        if (s.size() % 5 != 0) return -1;

        int cnt[5] = {};
        int active = 0;
        int ans = 0;

        for (char ch : s) {
            int idx;

            if (ch == 'c') idx = 0;
            else if (ch == 'r') idx = 1;
            else if (ch == 'o') idx = 2;
            else if (ch == 'a') idx = 3;
            else if (ch == 'k') idx = 4;
            else return -1;

            if (idx > 0 && cnt[idx - 1] <= cnt[idx])
                return -1;

            cnt[idx]++;

            if (ch == 'c') {
                active++;
                ans = max(ans, active);
            } 
            else if (ch == 'k') {
                active--;
            }
        }

        return active == 0 ? ans : -1;
    }
};