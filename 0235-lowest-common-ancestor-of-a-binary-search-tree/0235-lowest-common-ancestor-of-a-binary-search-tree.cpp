/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* nextnode1 = (root->val < p->val) ? root->right : root->left;
        TreeNode* nextnode2 = (root->val < q->val) ? root->right : root->left;
        if (nextnode1 == nextnode2)
            return helper(nextnode1, p, q);
        else {
            TreeNode* t1 = helper(nextnode1, p, q);
            TreeNode* t2 = helper(nextnode2, p, q);
            if (!t1)
                return t2;
            if (!t2)
                return t1;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};