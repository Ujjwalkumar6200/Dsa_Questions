class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end()); //6
        int index = -1;
        int i =0;
        for(int num : nums){
        if(num == maxi){
         index = i;
         continue;
        }
        if((2*num) > maxi ) return -1;
        i++;
        } return  index;
    }
};