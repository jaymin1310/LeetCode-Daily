/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while (temp || !st.empty()) {
            if (temp == nullptr) {
                temp = st.top();
                st.pop();
                res.push_back(temp->val);
                temp = temp->right;
            } else {
                st.push(temp);
                temp = temp->left;
            }
        }
        return res;
    }
};