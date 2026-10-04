class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> mat(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while(head != nullptr && top <= bottom && left <= right) {

            // 1. Left -> Right
            for(int j = left; j <= right && head != nullptr; j++) {
                mat[top][j] = head->val;
                head = head->next;
            }
            top++;

            // 2. Top -> Bottom
            for(int i = top; i <= bottom && head != nullptr; i++) {
                mat[i][right] = head->val;
                head = head->next;
            }
            right--;

            // 3. Right -> Left
            for(int j = right; j >= left && head != nullptr; j--) {
                mat[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;

            // 4. Bottom -> Top
            for(int i = bottom; i >= top && head != nullptr; i--) {
                mat[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return mat;
    }
};