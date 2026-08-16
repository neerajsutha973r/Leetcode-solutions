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
    int maxLevelSum(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int x=0;
            for(int i=0;i<s;i++){
                 TreeNode* node=q.front();
                 q.pop();
                 x+=node->val;
                 if(node->left)q.push(node->left);
                 if(node->right)q.push(node->right);
            }
            ans.push_back(x);

        }
        int maxs=INT_MIN;
        int x=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>maxs){
                x=i;
                maxs=ans[i];
            }
        }
        return x+1;
        
    }
};