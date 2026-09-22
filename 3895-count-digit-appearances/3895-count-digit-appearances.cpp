class Solution {
public:
    int count(int n,int digit){
        int num=n;
        int counter=0;
        while(num){
            int x=num%10;
            if(x==digit) counter++;
            num/=10;
        }
        return counter;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=count(nums[i],digit);
        }
        return ans;
    }
};