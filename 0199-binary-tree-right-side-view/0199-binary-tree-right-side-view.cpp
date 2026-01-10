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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int>res;
        queue<pair<TreeNode*,int>>qu;
        qu.push({root,0});
        while(!qu.empty()){
            int size=qu.size();
            while(size--){
                auto it=qu.front();
                qu.pop();
                TreeNode* front=it.first;
                if(front->left)
                    qu.push({front->left,it.second-1});
                if(front->right)
                    qu.push({front->right,it.second+1});
                if(size==0){
                    res.push_back(front->val);
                }
            }
        }
        return res;
    }
};