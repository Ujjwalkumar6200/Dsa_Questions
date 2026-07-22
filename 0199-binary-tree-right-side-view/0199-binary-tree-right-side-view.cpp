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
    void rightlevel(TreeNode* root, int level, vector<int>& rightview){
        if(root==NULL) return;

        if(rightview.size() == level) rightview.push_back(root->val);
        rightlevel(root->right,level+1,rightview);
        rightlevel(root->left,level+1,rightview);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightview;
        rightlevel(root,0,rightview);
        return rightview;

    }
};