class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int>mindq,maxdq;
        int i =0;
        int j =0;
        int ans = 0;

        while(j<n){
           while(!mindq.empty() && nums[mindq.back()]>=nums[j]) mindq.pop_back();
           mindq.push_back(j);

           while(!maxdq.empty() && nums[maxdq.back()]<=nums[j]) maxdq.pop_back();
           maxdq.push_back(j);

           while(nums[maxdq.front()] - nums[mindq.front()] > limit){
               if (mindq.front() == i) mindq.pop_front(); 

               if (maxdq.front() == i ) maxdq.pop_front();

               i++; 
           }
           ans = max(ans,j-i+1);
           j++;
        } return ans;

    }
};