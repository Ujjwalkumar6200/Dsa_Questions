/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelorder_traversal;
        if(root==nullptr) return levelorder_traversal;

        queue<TreeNode*>q;
        q.push(root);


        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i =0;i<size;i++){
                auto it = q.front();
                q.pop();
                if(it->left)q.push(it->left);
                if(it->right) q.push(it->right);
                level.push_back(it->val);
            } levelorder_traversal.push_back(level);
        } return levelorder_traversal;
    }
};