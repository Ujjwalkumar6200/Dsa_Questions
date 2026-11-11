
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;

        if (cost1 > costBoth && cost2 > costBoth) {
            return 1LL * max(need1, need2) * costBoth;
        }
        else if (costBoth >= cost1 + cost2) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }
        else {
            int common = min(need1, need2);

            long long ans = 1LL * common * costBoth;

            need1 -= common;
            need2 -= common;

            ans += 1LL * need1 * min(cost1, costBoth);
            ans += 1LL * need2 * min(cost2, costBoth);

            return ans;
        }
    }
};
