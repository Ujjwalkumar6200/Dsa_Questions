class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<int> brr = arr;
        sort(brr.begin(), brr.end());

        unordered_map<int, int> mp;
        int rank = 1;

        // assign ranks using for loop
        for (int i = 0; i < n; i++) {
            if (mp.find(brr[i]) == mp.end()) {
                mp[brr[i]] = rank++;
            }
        }

        // replace elements by rank
        for (int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};
