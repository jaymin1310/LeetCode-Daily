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
    TreeNode* helper(vector<int>&preorder,int low,int high,int & i){
        if(i>=preorder.size() || preorder[i]<=low || preorder[i]>=high)return nullptr;
        int val=preorder[i];
        TreeNode* root=new TreeNode(val);
        i++;
        root->left=helper(preorder,low,val,i);
        root->right=helper(preorder,val,high,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,INT_MIN,INT_MAX,i);
    }
};