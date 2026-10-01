class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int not_pick = max(left.first, left.second)
                     + max(right.first, right.second);

        int pick = root->val
                 + left.first
                 + right.first;

        return {not_pick, pick};
    }

    int rob(TreeNode* root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second);
    }
};