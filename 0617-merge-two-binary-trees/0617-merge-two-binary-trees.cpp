class Solution {
public:
    TreeNode* dfs(TreeNode* root1, TreeNode* root2) {

        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;

        TreeNode* node = new TreeNode(root1->val + root2->val);

        node->left = dfs(root1->left, root2->left);
        node->right = dfs(root1->right, root2->right);

        return node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};