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
    struct bst{
        bool isbst;
        int low;
        int high;
        int sum;
    };
    int ans=0;
public:
    bst helper(TreeNode* root){
        if(!root)return{true,INT_MAX,INT_MIN,0};
        bst obj1=helper(root->left);
        bst obj2=helper(root->right);
        if(obj1.isbst && obj2.isbst && (root->val>obj1.high && root->val<obj2.low)){
            int sum=obj1.sum+obj2.sum+root->val;
            ans=max(ans,sum);
            int newmin=min(root->val,obj1.low);
            int newmax=max(root->val,obj2.high);
            return{true,newmin, newmax,sum};
        }else{
            return{false,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) {
        bst obj=helper(root);
        return ans;
    }
};