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
    void flatten(TreeNode* root) {
        while(root){
            if(!root->left){
                root=root->right;
            }else{
                TreeNode* leftTree=root->left;
                while(leftTree->right && leftTree->right!=root){
                    leftTree=leftTree->right;
                }
                if(leftTree->right){
                    TreeNode* temp=root->right;
                    leftTree->right=temp;
                    root->right=root->left;
                    root->left=nullptr;
                    root=temp;
                }else{
                    leftTree->right=root;
                    root=root->left;
                }
            }
        }
    }
};