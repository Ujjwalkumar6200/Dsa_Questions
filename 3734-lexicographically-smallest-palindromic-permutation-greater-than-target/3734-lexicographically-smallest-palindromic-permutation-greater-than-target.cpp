class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int odd = 0, mid = -1;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) { odd++; mid = i; }
        }
        if (n % 2 == 0 && odd != 0) return "";
        if (n % 2 == 1 && odd != 1) return "";

        int half = n / 2;
        vector<int> left(26);
        for (int i = 0; i < 26; i++) left[i] = count[i] / 2;

        auto build = [&](string firstHalf) -> string {
            string reversed(firstHalf.rbegin(), firstHalf.rend());
            if (n % 2 == 1) return firstHalf + (char)('a' + mid) + reversed;
            return firstHalf + reversed;
        };

        vector<int> copyArr = left;
        int matched = 0;
        bool fullMatch = true;
        for (int i = 0; i < half; i++) {
            int c = target[i] - 'a';
            if (copyArr[c] == 0) { fullMatch = false; break; }
            copyArr[c]--;
            matched++;
        }

        if (fullMatch) {
            string firstHalf = target.substr(0, half);
            string answer = build(firstHalf);
            if (answer > target) return answer;
        }

        vector<int> use = left;
        for (int i = 0; i < matched; i++) use[target[i] - 'a']--;

        for (int pos = min(matched, half - 1); pos >= 0; pos--) {
            if (pos < matched) use[target[pos] - 'a']++;

            int tChar = target[pos] - 'a';
            for (int c = tChar + 1; c < 26; c++) {
                if (use[c] > 0) {
                    use[c]--;
                    string firstHalf = target.substr(0, pos) + (char)('a' + c);
                    string rest = "";
                    for (int x = 0; x < 26; x++)
                        rest += string(use[x], (char)('a' + x));
                    return build(firstHalf + rest);
                }
            }
        }

        return "";
    }
};