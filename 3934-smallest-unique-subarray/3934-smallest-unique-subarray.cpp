class Solution {
    const long long m = 1e9+7;
    const long long p = 1e5+3;

    long long modPow(long long a, long long b){
        long long res = 1;

        while(b > 0){
            if(b & 1)
                res = (res * a) % m;

            a = (a * a) % m;
            b >>= 1;
        }

        return res;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pow(n), invPow(n), hash(n);
        pow[0] = 1;
        for(int i = 1; i < n; i++){
            pow[i] = (pow[i-1] * p) % m;
        }
        invPow[n-1] = modPow(pow[n-1], m-2);
        for(int i = n-2; i >= 0; i--){
            invPow[i] = (invPow[i+1] * p) % m;
        }

        hash[0] = nums[0];
        for(int i = 1; i < n; i++){
            hash[i] = (hash[i-1] + (nums[i] * pow[i]) % m) % m;
        }

        auto solve = [&](int l) {
            map<long long, int> mp;
            for(int i = 0; i < n; i++){
                int j = i + l - 1;
                if(j >= n) continue;

                long long val = (hash[j] - (i > 0 ? hash[i-1] : 0) + m) % m;
                val = (val * invPow[i]) % m;
                mp[val]++;
            }
            for(auto it: mp)
                if(it.second == 1) return true; 
            return false;
        };

        int hi = n, lo = 0, mid;
        while(hi - lo > 1){
            mid = (hi + lo) / 2;
            if(solve(mid)) hi = mid;
            else lo = mid;
        }

        return hi;
    }
};