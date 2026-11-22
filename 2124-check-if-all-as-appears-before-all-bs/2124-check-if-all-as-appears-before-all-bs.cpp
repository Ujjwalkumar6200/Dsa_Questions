class Solution {
public:
    bool checkString(string s) {
        int b1 = 0;

        for(auto it : s){
            if(it=='a'){
                if(b1>0) return false;
            }
            else b1++;
        }
        return true;
    }
};