class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        std::vector<int> prefixMin(n, INT_MAX);
        std::vector<int> suffixMin(n, INT_MAX);
        
        // Left to Right Pass
        int l = 0, h = 0, sum = 0, minlen = INT_MAX;
        while (h < n) {
            sum += arr[h];
            while (sum > target) {
                sum -= arr[l++];
            }
            if (sum == target) {
                minlen = std::min(minlen, h - l + 1);
            }
            prefixMin[h] = minlen;
            h++;
        }
        
        // Right to Left Pass
        l = n - 1; 
        h = n - 1; 
        sum = 0; 
        minlen = INT_MAX;
        
        while (l >= 0) {
            sum += arr[l];
            while (sum > target) {
                sum -= arr[h--];
            }
            if (sum == target) {
                minlen = std::min(minlen, h - l + 1);
            }
            suffixMin[l] = minlen;
            l--;
        }
        
        // Find optimal division point
        int res = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (prefixMin[i] != INT_MAX && suffixMin[i + 1] != INT_MAX) {
                res = std::min(res, prefixMin[i] + suffixMin[i + 1]);
            }
        }
        
        return (res == INT_MAX) ? -1 : res;
    }
};