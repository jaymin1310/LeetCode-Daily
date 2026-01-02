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
    int height( TreeNode* root){
        if(root==nullptr)return 0;
        int leftHeight=1+height(root->left);
        int rightHeight=1+height(root->right);
        if(leftHeight==0 || rightHeight==0)return -1;
        return (abs(leftHeight-rightHeight))<=1?max(leftHeight,rightHeight):-1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        return height(root)!=-1;
    }
};