class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9+7;

        vector<long long>last(26,0);

        long long dp = 1; //empty subsequence

        for(char c : s){
            int i = c - 'a';

            long long old = dp;

            dp = (2*dp)%MOD;

            dp = (dp-last[i] + MOD) % MOD;

            last[i] = old;
        }

        return (dp-1+MOD)%MOD;
    }
};