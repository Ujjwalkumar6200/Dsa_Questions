class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi = 0;
        for(auto& it : st){
            if(!st.count(it-1)){
                 int  currentNum = it;
                 int currentStreak = 1;

                 while (st.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                } maxi = max(maxi,currentStreak);
            }
        } return maxi;

    }
};