class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int ans =0;
        for(int i =0;i<n;i++){
            if(s[i]=='(') left++;
            else if(s[i]==')'){
                if(left>0) left--;
                else right++;
            }
        } ans+= abs(left+right);
        return ans;
    }
};