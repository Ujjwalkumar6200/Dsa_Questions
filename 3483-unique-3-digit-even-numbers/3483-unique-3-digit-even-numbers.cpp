class Solution {
public:
    unordered_set<int> st;

    void helper(vector<int>& digits, vector<bool>& used, int num, int len) {
        if (len == 3) {
            if (num % 2 == 0) {
                st.insert(num);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;

            if (len == 0 && digits[i] == 0) continue;

            used[i] = true;

            helper(digits, used, num * 10 + digits[i], len + 1);

            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);

        helper(digits, used, 0, 0);

        return st.size();
    }
};