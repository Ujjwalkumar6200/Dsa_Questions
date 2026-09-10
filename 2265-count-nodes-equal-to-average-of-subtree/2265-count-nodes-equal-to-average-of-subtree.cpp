class Solution {
public:
    int nodes = 0;

    int helper(TreeNode* root, int& sum, int& count) {
        if (root == NULL) {
            sum = 0;
            count = 0;
            return 0;
        }

        int leftSum = 0, leftCount = 0;
        int rightSum = 0, rightCount = 0;

        helper(root->left, leftSum, leftCount);
        helper(root->right, rightSum, rightCount);

        sum = leftSum + rightSum + root->val;
        count = leftCount + rightCount + 1;

        if (sum / count == root->val)
            nodes++;

        return 0;
    }

    int averageOfSubtree(TreeNode* root) {
        int sum = 0, count = 0;
        helper(root, sum, count);
        return nodes;
    }
};