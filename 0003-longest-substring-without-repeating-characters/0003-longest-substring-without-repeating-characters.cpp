class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; // Changed to char to match the string
        int n = s.length();
        int i = 0, j = 0; // Both pointers start at the beginning
        int maxi = 0;

        while (j < n) {
            // If s[j] is NOT in the set, expand the window
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                maxi = max(maxi, j - i + 1);
                j++;
            } 
            // If s[j] IS in the set, we have a duplicate. Shrink from the left.
            else {
                st.erase(s[i]);
                i++;
            }
        } 
        
        return maxi;
    }
};