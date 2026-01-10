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
    void recursion(vector<int>&res,TreeNode* root,int level){
        if(!root)return ;
        if(res.size()==level)
            res.push_back(root->val);
        recursion(res,root->right,level+1);
        recursion(res,root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(res,root,0);
        return res;
    }
};