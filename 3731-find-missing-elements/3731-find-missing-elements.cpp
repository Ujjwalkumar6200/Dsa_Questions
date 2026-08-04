class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        vector<int> result;
        set<int> s(nums.begin(),nums.end());
        for(int i = low;i<=high;i++){
            if(s.find(i)==s.end()) result.push_back(i);
        } 
        return result;
    }
};