class Solution {
public:

    bool ispossible(const vector<int>& piles,int v, int h){
        long long need = 0;
        for(int i=0;i<piles.size();i++){
                need += ceil((double)piles[i]/(double)v);
        }
        if(need<=h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = *max_element(piles.begin(), piles.end());
        int ans =0;
        while(low<=high){
            int mid = (low+high) >> 1;
            if(ispossible(piles,mid,h)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        } return ans;
    } 
};