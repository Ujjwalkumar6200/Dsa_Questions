class Solution {
private:
    // Returns {max1, max2} for the substring s[i...j]
    pair<int, int> solve(int i, int j, const string& s) {
        // Base case: Partition size of 1
        if (i == j) {
            return {s[i] - '0', -1}; // -1 indicates no second digit exists yet
        }

        // Partition the interval
        int k = i + (j - i) / 2; 

        // Solve sub-intervals
        pair<int, int> left = solve(i, k, s);
        pair<int, int> right = solve(k + 1, j, s);

        // Merge states: we have up to 4 candidates, we need the top 2
        int candidates[] = {left.first, left.second, right.first, right.second};
        int max1 = -1, max2 = -1;
        
        for (int x : candidates) {
            if (x >= max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
        }
        
        return {max1, max2};
    }

public:
    int maxProduct(int n) {
        string s = to_string(n);
        pair<int, int> result = solve(0, s.length() - 1, s);
        return result.first * max(0, result.second); 
    }
};