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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,int &preidx,int left,int right) {
        if(left>right) return NULL;
        TreeNode* root=new TreeNode(postorder[preidx]);
        int inoidx=search(inorder,left,right,postorder[preidx]);
        preidx--;
        root->right=helper(postorder,inorder,preidx,inoidx+1,right);
        root->left=helper(postorder,inorder,preidx,left,inoidx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int preidx=postorder.size()-1;
        return helper(postorder,inorder,preidx,0,inorder.size()-1);
    }
};