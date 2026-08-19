class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> mat;

        for (auto &it : reservedSeats) {
            int row = it[0];
            int col = it[1];

            mat[row].push_back(col);
        }

        int ans = (n - mat.size()) * 2;

        for (auto &[row, seats] : mat) {

            vector<int> seat(11, 0);

            for (int col : seats) {
                seat[col] = 1;
            }

            // Left: 2 3 4 5
            bool left =
                seat[2] == 0 &&
                seat[3] == 0 &&
                seat[4] == 0 &&
                seat[5] == 0;

            // Middle: 4 5 6 7
            bool middle =
                seat[4] == 0 &&
                seat[5] == 0 &&
                seat[6] == 0 &&
                seat[7] == 0;

            // Right: 6 7 8 9
            bool right =
                seat[6] == 0 &&
                seat[7] == 0 &&
                seat[8] == 0 &&
                seat[9] == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};