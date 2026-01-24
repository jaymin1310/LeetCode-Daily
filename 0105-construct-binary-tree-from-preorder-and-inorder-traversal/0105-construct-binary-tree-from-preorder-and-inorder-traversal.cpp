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
    unordered_map<int,int>mp;
    int traverse=0;
    TreeNode* recursion(vector<int>&preorder,int low,int high){
        if(low>high)return nullptr;
        int val=preorder[traverse];
        traverse++;
        TreeNode* temp=new TreeNode(val);
        int ind=mp[val];
        if(low==high){
            return temp;
        }
        temp->left=recursion(preorder,low,ind-1);
        temp->right=recursion(preorder,ind+1,high);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return recursion(preorder,0,n-1);
    }
};