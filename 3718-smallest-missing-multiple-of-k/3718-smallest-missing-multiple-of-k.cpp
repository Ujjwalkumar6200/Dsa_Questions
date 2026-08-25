class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> d(nums.begin(),nums.end());
        int multiple = k;
        while(d.count(multiple)){
            multiple+= k;
        }
        return multiple;
    }
};