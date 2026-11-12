class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length = nums.size();
        int inc = 1;
        int dnc = 1;
        int incmax =1;
        int dncmax = 1;
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc++;
                incmax = max(inc,incmax);
            }
            else inc = 1;
        }

            for(int i = length-2;i>=0;i--){
                if(nums[i] > nums[i+1]){
                    dnc++;
                dncmax = max(dnc,dncmax);
            }
            else dnc = 1;
            } 
         return max(incmax,dncmax);
    }
};