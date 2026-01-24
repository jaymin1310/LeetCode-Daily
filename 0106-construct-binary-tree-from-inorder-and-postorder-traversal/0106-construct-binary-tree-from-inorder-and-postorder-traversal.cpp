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
    TreeNode* build(vector<int>& postorder,int low,int high,int &traverse,unordered_map<int,int>&mp){
        if(low>high)return nullptr;
        int val=postorder[traverse];
        traverse--;
        TreeNode* temp=new TreeNode(val);
        int ind=mp[val];
        temp->right=build(postorder,ind+1,high,traverse,mp);
        temp->left=build(postorder,low,ind-1,traverse,mp);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int traverse=n-1;
        return build(postorder,0,n-1,traverse,mp);
    }
};