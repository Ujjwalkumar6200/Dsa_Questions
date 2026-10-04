class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());
        int index = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == maxi) {
                index = i;
            }
            else if (2 * nums[i] > maxi) {
                return -1;
            }
        }

        return index;
    }
};