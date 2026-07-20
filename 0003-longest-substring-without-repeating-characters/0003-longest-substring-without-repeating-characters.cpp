class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each ASCII character
        vector<int> hash(256, -1); 
        
        int n = s.length();
        int i = 0, j = 0;
        int maxi = 0;

        while (j < n) {
            // If we've seen this character before AND it's inside our current window
            if (hash[s[j]] != -1 && hash[s[j]] >= i) {
                // Jump the left pointer straight to the right of the duplicate
                i = hash[s[j]] + 1; 
            }
            
            // Record/Update the latest index of this character
            hash[s[j]] = j;
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};