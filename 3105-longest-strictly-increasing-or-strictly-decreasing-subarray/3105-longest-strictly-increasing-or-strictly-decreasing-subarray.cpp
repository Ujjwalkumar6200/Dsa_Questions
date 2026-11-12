class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length = nums.size();
        int inc = 1;
        int dnc = 1;
        int maxi =1;
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dnc = 1;
            }
            else if(nums[i] < nums[i-1]){
                    dnc++;
                    inc = 1;
            }
            else {
                inc = 1;
                dnc = 1;
            }
             maxi = max(maxi, max(inc, dnc));
         } return maxi;

    }
};