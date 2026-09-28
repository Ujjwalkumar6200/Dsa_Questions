class Solution {
public:
    int maxDepth(string s) {
        int length = 0;
        int maxi = INT_MIN;
        for(int i =0;i<s.length();i++){
            if(s[i]=='(') {
                length++;
            maxi = max(maxi,length);
            }
           else if(s[i]==')'){
             length--;}
        } return maxi;
    }
};