class Solution {
public:
        
    int gcd(int a, int b){
        while(b){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<int> prefgcd(n);
        int mx=nums[0];
        prefgcd[0]=mx;
        for(int i=1;i<n;i++){
          mx = max(mx,nums[i]);
          prefgcd[i]=gcd(mx,nums[i]);
        }
        sort(prefgcd.begin(),prefgcd.end(),greater<int>());
        int left=0;
        int right =n-1;
        while(left<right){
            ans+=gcd(prefgcd[left],prefgcd[right]);
            left++;
            right--;
        }
        return ans;
    }
};