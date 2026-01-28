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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        if(!root)return newnode;
        TreeNode* temp=root;
        TreeNode* prev=root;
        while(temp){
            prev=temp;
            if(temp->val<val){
                temp=temp->right;
            }else{
                temp=temp->left;
            }
        }
        if(prev->val>val)prev->left=newnode;
        else prev->right=newnode;
        return root;
    }
};