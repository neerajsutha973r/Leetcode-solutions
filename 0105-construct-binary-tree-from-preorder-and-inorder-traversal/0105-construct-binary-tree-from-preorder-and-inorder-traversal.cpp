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
    int search(vector<int>&inorder,int left,int right,int val){
        int a;
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                  a=i;
                  break;
            }
        }
        return a;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preidx,int left,int right) {
        if(left>right) return NULL;
        TreeNode* root=new TreeNode(preorder[preidx]);
        int inoidx=search(inorder,left,right,preorder[preidx]);
        preidx++;
        root->left=helper(preorder,inorder,preidx,left,inoidx-1);
        root->right=helper(preorder,inorder,preidx,inoidx+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx=0;
        return helper(preorder,inorder,preidx,0,inorder.size()-1);
    }
};