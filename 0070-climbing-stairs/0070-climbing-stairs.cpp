class Solution {
public:
    int climbStairs(int n) {

        if (n == 1)
            return 1;
        int prev2 = 1;
        int prev = 2;
        int curri=2;
        for (int i = 3; i <= n; i++) {
             curri = prev+prev2;
             prev2=prev;
             prev = curri;
        }

        return curri;
    }
};