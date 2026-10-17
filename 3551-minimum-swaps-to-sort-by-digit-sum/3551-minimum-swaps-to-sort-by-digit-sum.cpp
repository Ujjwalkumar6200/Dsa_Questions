class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end(), [this](const auto& a, const auto& b) {
            int sum_a = digitSum(a.first), sum_b = digitSum(b.first);

            if (sum_a != sum_b)
                return sum_a < sum_b;

            return a.first < b.first;
        });

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || temp[i].second == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = temp[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};