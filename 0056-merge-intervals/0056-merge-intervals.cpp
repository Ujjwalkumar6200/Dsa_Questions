class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto &curr : intervals) {

            if (ans.empty() || ans.back()[1] < curr[0]) {
                ans.push_back(curr);
            }
            else {
                ans.back()[1] = max(ans.back()[1], curr[1]);
            }
        }

        return ans;
    }
};