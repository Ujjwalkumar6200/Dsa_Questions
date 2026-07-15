class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s(nums.begin(),nums.end()); // remove duplicates;
        vector<int> v(s.begin(),s.end());
        sort(v.begin(),v.end());      // sort to have everything in range;
        int m = v.size();   //  it gives size of array without duplicate;

        int j =0;
        int maxi = INT_MIN;
        int cnt =0;
        for(int i =0;i<m;i++){
            while(j<m && v[j] < v[i]+n){
                j++;
                cnt++;
            } maxi = max(maxi,cnt);
            cnt--;
        } return n-maxi;


    }
};