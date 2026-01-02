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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>st;
        if(root==nullptr)return 0;
        st.push(root);
        int level=0;
        while(!st.empty()){
            int size=st.size();
            while(size--){
                TreeNode* top=st.front();
                st.pop();
                if(top->left)st.push(top->left);
                if(top->right)st.push(top->right);
            }
            level++;
        }
        return level;
    }
};