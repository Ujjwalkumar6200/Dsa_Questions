
class Solution {
public:
    bool is_possible(int side, vector<vector<int>>& pref,
                     int m, int n) {
        int minR = m, maxR = -1;
        int minC = n, maxC = -1;

        for (int i = 0; i + side <= m; i++) {
            for (int j = 0; j + side <= n; j++) {

                int sum = pref[i + side][j + side]
                        - pref[i][j + side]
                        - pref[i + side][j]
                        + pref[i][j];

                if (sum == side * side) {
                    minR = min(minR, i);
                    maxR = max(maxR, i);
                    minC = min(minC, j);
                    maxC = max(maxC, j);
                }
            }
        }

        if (maxR == -1) return false;

        return (maxR - minR >= side ||
                maxC - minC >= side);
    }

    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Build 2D prefix sum
        vector<vector<int>> pref(m + 1,
                                 vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j] + pref[i][j + 1]
                    + pref[i + 1][j] - pref[i][j];
            }
        }


        int high = min(min(m, n), max(m, n) / 2);

        for (int side = high; side >= 1; side--) {
            if (is_possible(side, pref, m, n)) {
                return side * side;
            }
        }

        return 0;
    }
};
