class Solution {
public:

    bool isPossible( const vector<int>& weights,int daily,int days){
        long long cap=0;
        int day =1;
        for(int i =0;i<weights.size();i++){
            if(cap+weights[i]>daily){
                day++;
                cap = weights[i];
            } else cap+=weights[i];
        }
        if(day<=days) return true;
        else return false;

    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans =0;
        while(low<=high){
            int mid = (low+high) >> 1;
            if(isPossible(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        } return ans;
    }
};