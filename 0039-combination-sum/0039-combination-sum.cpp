class Solution {
public:
    void prints(int ind, vector<int>& ds, vector<vector<int>>& sub,int n , vector<int>& candidates, int target){

        if(ind==n){
            if(target==0){
                sub.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<= target){
        ds.push_back(candidates[ind]);
        prints(ind,ds,sub,n,candidates,target - candidates[ind]);
        ds.pop_back();
        }
        prints(ind+1,ds,sub,n,candidates,target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sub;
        vector<int> ds;
        prints(0,ds,sub,candidates.size(),candidates,target);
        return sub;
    }
};