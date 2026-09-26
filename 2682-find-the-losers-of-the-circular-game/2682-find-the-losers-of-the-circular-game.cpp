class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans , temp(n,0);
        int i = 0 , count = 1;
        while(temp[i] < 1){
            temp[i]++;
            i = (i+(k*count))%n;
            count++;
        }
        for(int i = 0; i<n; i++)
        if(temp[i] == 0)
        ans.push_back(i+1);

        return ans;
    }
};