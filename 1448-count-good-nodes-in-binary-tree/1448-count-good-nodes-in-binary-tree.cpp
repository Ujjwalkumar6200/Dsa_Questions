class Solution {
public:
    int ans=0;
    void solve(TreeNode* root,int maxNodeSeen){
        if(!root) return;

        if(root->val>=maxNodeSeen){
            ans++;
            maxNodeSeen=root->val;
        }

        solve(root->left,maxNodeSeen);
        solve(root->right,maxNodeSeen);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        solve(root,root->val);
        return ans;
    }
};