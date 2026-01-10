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
    bool recursion(TreeNode* leftnode,TreeNode* rightnode){
        if(!leftnode || !rightnode) 
            return leftnode==rightnode;
        return (leftnode->val==rightnode->val) &&
            recursion(leftnode->left,rightnode->right) && 
            recursion(leftnode->right,rightnode->left);

    }
    bool isSymmetric(TreeNode* root) {
        return recursion(root->left,root->right);
    }
};