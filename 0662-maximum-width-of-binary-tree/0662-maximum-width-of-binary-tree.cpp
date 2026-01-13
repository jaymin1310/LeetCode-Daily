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
    //  void recursionright(TreeNode* root,int i){
    //     if(root==nullptr)return;
    //     if(root->right){
    //         recursion(root->left,i+1);
    //         rightind=max(rightind,i+1);
    //     }
    //     if(root->right){
    //         recursion(root->right,i+1);
    //         rightind=max(rightind,i+1);
    //     }
    // }
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,unsigned long long>>qu;
       unsigned long long ans=0;
       qu.push({root,0});
       while(!qu.empty()){
            int size=qu.size();
            unsigned long long leftmost=qu.front().second;
            unsigned long long rightmost=qu.back().second;
            ans=max(ans,rightmost-leftmost+1);
            while(size--){
                auto it=qu.front();
                qu.pop();
                if(it.first->left){
                    qu.push({it.first->left,2ULL*it.second+1});
                }
                if(it.first->right){
                    qu.push({it.first->right,2ULL*it.second+2});
                }
            }
       }
       return ans;
    }
};