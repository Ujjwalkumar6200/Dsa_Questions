class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5 != 0) return -1;
        
        int frogs = 0, ans = 0;
        unordered_map<char, int> mp;
        
        for (char ch : croakOfFrogs) {
            if (ch == 'c') frogs++, mp['c']++;
            else if (ch == 'r' && mp['c'] > mp['r']) mp['r']++;
            else if (ch == 'o' && mp['r'] > mp['o']) mp['o']++;
            else if (ch == 'a' && mp['o'] > mp['a']) mp['a']++;
            else if (ch == 'k' && mp['a'] > mp['k']){
                ans = max(ans, frogs);
                frogs--;
                mp['k']++;
            }
            else return -1;
        }
        return frogs==0 ? ans : -1;
    }
};