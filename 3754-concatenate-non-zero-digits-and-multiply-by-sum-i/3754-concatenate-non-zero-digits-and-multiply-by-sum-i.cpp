class Solution {
public:
    long long sumAndMultiply(int n) {
    string a = to_string(n),b="";
        for(char ch: a) if(ch!='0') b +=ch;
        if(b.empty()) return 0;
        long long x = stoll(b),sum=0;
        for(char ch:b) sum+= ch-'0';
        return x * sum;
    }
};