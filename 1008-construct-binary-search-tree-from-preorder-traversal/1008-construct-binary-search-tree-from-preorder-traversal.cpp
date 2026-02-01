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
    TreeNode* helper(vector<int>&preorder,int upper,int & i){
        if(i>=preorder.size() || preorder[i]>upper)return nullptr;
        int val=preorder[i];
        TreeNode* root=new TreeNode(val);
        i++;
        root->left=helper(preorder,val,i);
        root->right=helper(preorder,upper,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,INT_MAX,i);
    }
};