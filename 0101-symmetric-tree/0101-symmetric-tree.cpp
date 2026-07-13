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
    bool isSymmetric(TreeNode* root) {

            if(root==NULL) return true;
           queue<pair<TreeNode*,TreeNode*>> q;
           q.push({root->left,root->right});

           while(!q.empty()){
            auto it = q.front(); q.pop();
            TreeNode* left = it.first;
            TreeNode* right = it.second;

            if(left==NULL && right == NULL) continue;
            if(left==NULL || right==NULL) return false;
            if(left->val!=right->val) return false;
            q.push({left->right,right->left});
            q.push({left->left,right->right}); 

           }
            return true;
    }
};