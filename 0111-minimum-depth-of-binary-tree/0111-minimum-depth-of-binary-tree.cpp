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
    int ans;
    int mind=INT_MAX;
    void dfs(TreeNode* root,int ans){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
             mind=min(mind,ans);
             return;
        }
        if(root->left) dfs(root->left,ans+1);
        if(root->right) dfs(root->right,ans+1);
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        dfs(root,1);
        return mind;
    }
};