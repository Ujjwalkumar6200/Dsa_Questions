class Solution {
public:
    pair<int, int> helper(TreeNode* root, int& nodes) {
        if (root == nullptr)
            return {0, 0};  // {sum, count}

        auto left = helper(root->left, nodes);
        auto right = helper(root->right, nodes);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val)
            nodes++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int nodes = 0;
        helper(root, nodes);
        return nodes;
    }
};