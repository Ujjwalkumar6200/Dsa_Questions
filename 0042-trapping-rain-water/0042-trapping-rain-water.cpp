class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int left = 0;
        int right = n-1;
        int lmax = height[left];
        int rmax = height[right];
        int total = 0;
        while(left<right){
            if(height[left]<height[right]){
                lmax = max(lmax,height[left]);
                total += lmax-height[left];
                left++;
            } else {
                rmax = max(rmax,height[right]);
                total+= rmax-height[right];
                right --;
            }
        } return total;
        
        
    }
};