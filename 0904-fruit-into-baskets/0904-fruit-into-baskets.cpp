class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n = fruits.size(), k =2;
      unordered_map<int,int> mpp;
      int i =0,j=0, maxi =0;
      while(j<n){
        mpp[fruits[j]]++;
        if(mpp.size()<=k){
            maxi= max(maxi,j-i+1);
            j++;

        }
        else if(mpp.size()>k){
          while(mpp.size()>k){
            mpp[fruits[i]]--;
            if(mpp[fruits[i]]==0){
              mpp.erase(fruits[i]);
            }i++;
          } j++;
        }
      } return maxi;
    }
};