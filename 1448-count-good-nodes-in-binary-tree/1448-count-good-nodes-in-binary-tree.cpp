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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        int ans =0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int maxSofar = it.second;

            if(node->val>=maxSofar){
                maxSofar = node->val;
                ans++;
            }
            if(node->left) q.push({node->left,maxSofar});
            if(node->right) q.push({node->right,maxSofar});

        } return ans;
    }
};