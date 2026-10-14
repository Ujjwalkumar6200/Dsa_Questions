class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum>9*num) return ans;
        for(int i =0;i<num;i++){
            int get = min(9, sum);
            ans.push_back('0'+get);
            sum = sum-get;
        }
        if(sum!=0) return "";
        return ans;
    }
};