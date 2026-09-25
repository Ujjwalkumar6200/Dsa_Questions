class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        int total = 0, res = 0;
        int mn = INT_MAX, mx = INT_MIN;
        int n = A.size();

        for (int i = 0; i < n - 1; i++) {
            int a = A[i], b = A[i + 1];

            total += abs(a - b);

            res = max(res, abs(A[0] - b) - abs(a - b));
            res = max(res, abs(A[n - 1] - a) - abs(a - b));

            mn = min(mn, max(a, b));
            mx = max(mx, min(a, b));
        }

        return total + max(res, 2 * (mx - mn));
    }
};