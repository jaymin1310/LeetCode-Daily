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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        while(root){
            if(!root->left){
                res.push_back(root->val);
                root=root->right;
            }else{
                TreeNode* leftTree=root->left;
                while(leftTree->right && leftTree->right!=root){
                    leftTree=leftTree->right;
                }
                if(leftTree->right){
                    res.push_back(root->val);
                    leftTree->right=nullptr;
                    root=root->right;
                }else{
                    leftTree->right=root;
                    root=root->left;
                }  
            }
        }
        return res;
    }
};