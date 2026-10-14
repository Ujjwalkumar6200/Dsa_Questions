class Solution {
private:
    int leftCount = 0, rightCount = 0;
    int dfs(TreeNode* root, int x) {
        if (!root) return 0;
        int left = dfs(root->left, x);
        int right = dfs(root->right, x);
        if (root->val == x) {
            leftCount = left;
            rightCount = right;
        }
        return left + right + 1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root, x);
        int parent = n - leftCount - rightCount - 1;
        int maxi = max(parent , max(leftCount, rightCount));
        return maxi * 2 > n;
    }
};