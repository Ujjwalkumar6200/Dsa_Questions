class Solution {
public:

    vector<int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        vector<int> dp(2);

        // Current node ko pick nahi kiya
        dp[0] = max(left[0], left[1])
              + max(right[0], right[1]);

        // Current node ko pick kiya
        // To direct children ko pick nahi kar sakte
        dp[1] = root->val
              + left[0]
              + right[0];

        return dp;
    }

    int rob(TreeNode* root) {
        vector<int> result = solve(root);

        return max(result[0], result[1]);
    }
};