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
    long long mul=1;
    long long recursion(TreeNode* root,long long sum){
        if(root==nullptr)return 0;
        long long left=recursion(root->left,sum);
        long long right=recursion(root->right,sum);
        long long tempsum=left+right+root->val;
        mul=max(mul,tempsum*(sum-tempsum));
        return tempsum;
    }
    int maxProduct(TreeNode* root) {
        long long sum=0;
        int MOD=1e9+7;
        if(!root)return 0;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* front=qu.front();
            sum+=front->val;
            qu.pop();
            if(front->left)qu.push(front->left);
            if(front->right)qu.push(front->right);
        }
        recursion(root,sum);
        return mul%MOD;
    }
};