class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum =0;
        int maxi =0;

        for(int& it : nums){
            sum+=it;
            int rem = sum-k;
            if(mpp.find(rem)!=mpp.end()){
                maxi+=mpp[rem];
            }
            mpp[sum]++; 
        } return maxi;
    }
};