class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for(int s: nums){
            sq.push_back(1LL*s*s);
        }
        sort(sq.begin(),sq.end());
        long long ans = 0;
        int n = sq.size();
        for(int i =0;i<sq.size();i++){
            if(i<n/2) ans-= sq[i];
            else ans +=sq[i];
        } return ans;
    }
};