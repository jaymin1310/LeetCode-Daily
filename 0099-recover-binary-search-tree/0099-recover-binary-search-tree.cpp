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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = new TreeNode(INT_MIN);
        TreeNode* temp = root;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        while (temp) {
            if (!temp->left) {
                if (temp->val < prev->val) {
                    if (!first)
                        first = prev;
                    second = temp;
                }
                prev = temp;
                temp = temp->right;
            } else {
                TreeNode* left = temp->left;
                while (left->right && left->right != temp) {
                    left = left->right;
                }
                if (!left->right){
                    left->right = temp;
                    temp=temp->left;
                }
                else {
                    left->right = nullptr;
                    if (temp->val < prev->val) {
                        if (!first)
                            first = prev;
                        second = temp;
                    }
                    prev = temp;
                    temp = temp->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};