class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long mod = 1'000'000'007;
        int n = s.length();
        vector<long long> a(n+1,0),b(n+1,0),c(n+1,0),d(n+1,1);
        for(int i =1;i<=n;i++) d[i] =(d[i-1]*10) % mod;
        for(int i =0;i<n;i++){
            a[i+1]=a[i];
            b[i+1] = b[i];
            c[i+1] = c[i];
            if(s[i]!='0'){
                int e =s[i]-'0';
                a[i+1] = (a[i]*10+e)%mod;
                b[i+1] += e;
                c[i+1]++;
            }
        }
        vector<int> res;
        res.reserve(queries.size());
        for(auto &it : queries){
            int f = it[0], g =it[1];
            long long count = c[g+1] - c[f];
            long long sum = b[g+1] - b[f];
            if(count==0){
                res.push_back(0);
                continue;
            }
            long long h = (a[g+1]-(a[f] * d[count]) % mod + mod) % mod;
            res.push_back((h*sum) % mod);
        } return res;
    }
};