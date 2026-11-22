class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;

        for(char c : s)
            mpp[c]++;

        int ans = 0;
        bool odd = false;

        for(auto &[ch, freq] : mpp) {
            ans += freq - (freq % 2);
            if(freq % 2)
                odd = true;
        }

        return ans + odd;
    }
};