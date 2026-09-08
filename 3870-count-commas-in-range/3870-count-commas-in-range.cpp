class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int cnt = s.size();
        if(cnt<4) return 0;
        else return n-1000+1;
    }
};