class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end()); // nums become unique;
        vector<int> arr(s.begin(), s.end());
        sort(arr.begin(), arr.end());// it comes in range

        int maxCount = 0;
        int j = 0;
        int news = arr.size();
        // abb duplicate hatane k baad range mai chahiye na
        for (int i = 0; i < arr.size(); i++) {
            while (j < news && arr[j] < arr[i] + n) {
                j++;
            }
            maxCount = max(maxCount, j - i);
        }

        return n - maxCount;
    }
};
