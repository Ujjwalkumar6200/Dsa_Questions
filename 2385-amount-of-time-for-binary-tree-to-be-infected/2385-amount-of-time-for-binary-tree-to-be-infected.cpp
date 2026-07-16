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
    TreeNode* mapParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* startp = nullptr;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val== start) startp = node;
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
                }
            if(node->right){
            parent[node->right] = node;
             q.push(node->right);
            }

        } return startp;
    }


    int amountOfTime(TreeNode* root, int start) {
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* startNode = mapParent(root, parent, start);

        queue<TreeNode*> q;
        int maxT=-1;
        q.push(startNode);
        visited.insert(startNode);

        while(!q.empty()){
            int size = q.size();
            maxT++;
            for(int i =0;i<size;i++){
                 TreeNode* node = q.front();
                 q.pop();
                 if(node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                    }
                 if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                  q.push(node->right);
                  }
                 if(parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                    }
            }

        } return maxT;
    }
};