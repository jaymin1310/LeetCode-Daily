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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>res;
        TreeNode* temp=root;
        TreeNode* lastVisited=nullptr;
        while(temp || !st.empty()){
            if(temp==nullptr){
                TreeNode* top=st.top();
                if(top->right && lastVisited!=top->right){
                    temp=top->right;
                }else{
                    res.push_back(top->val);
                    st.pop();
                    lastVisited=top;    
                }
            }
            else{
                st.push(temp);
                temp=temp->left;
            }  
        }
        return res;
    }
};