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
    int leftHeight(TreeNode* root){
        if(!root)return 0;
        return leftHeight(root->left)+1;
    }
    int rightHeight(TreeNode* root){
        if(!root)return 0;
        return rightHeight(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        if(leftHeight(root)==rightHeight(root))return pow(2,leftHeight(root))-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};