class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        int ans = 0;

        for(int& num: nums){
            if(n%i==0){
                ans += num * num;
            }
            i++;
        }
        return ans;
    }
};