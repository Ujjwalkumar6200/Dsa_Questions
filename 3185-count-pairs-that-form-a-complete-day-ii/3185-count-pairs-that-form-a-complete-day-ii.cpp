#include <vector>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // Frequency array to store the count of each remainder (0 to 23)
        vector<long long> remainder_counts(24, 0);
        long long day = 0;
        
        for (int h : hours) {
            int r = h % 24;
            
            // Calculate the required remainder to make a multiple of 24
            int target = (24 - r) % 24;
            
            // Add the number of times we've previously seen the target remainder
            day += remainder_counts[target];
            
            // Update the frequency of the current remainder
            remainder_counts[r]++;
        }
        
        return day;
    }
};