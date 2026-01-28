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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = root;
        TreeNode* prev = nullptr;
        while (target) {
            TreeNode* temp = target;
            if (target->val == key) {
                break;
            } else if (target->val > key) {
                target = target->left;
            } else {
                target = target->right;
            }
            prev = temp;
        }
        if (target) {
            if (!target->left && !target->right) {
                if (!prev)
                    return nullptr;
                if (prev->left == target) {
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
                delete target;
            } else if (!prev) {
                TreeNode* newroot;
                TreeNode* leftmax = target->left;
                if (!leftmax) {
                    TreeNode* temp = target->right;
                    delete target;
                    return temp;
                }
                TreeNode* prevroot = target;
                while (leftmax->right) {
                    prevroot = leftmax;
                    leftmax = leftmax->right;
                }
                newroot = leftmax;
                if (prevroot != target) {
                    prevroot->right = leftmax->left;
                    leftmax->left = target->left;
                }
                leftmax->right = target->right;
                delete target;
                return newroot;
            } else {
                if (prev->left == target) {
                    TreeNode* leftmax = target->left;
                    if (!leftmax) {
                        prev->left = target->right;
                    } else {
                        TreeNode* prevroot = target;
                        while (leftmax->right) {
                            prevroot = leftmax;
                            leftmax = leftmax->right;
                        }
                        if (prevroot != target) {
                            prevroot->right = leftmax->left;
                            leftmax->left = target->left;
                        }
                        prev->left = leftmax;
                        leftmax->right = target->right;
                    }
                    delete target;
                } else {
                    TreeNode* prevroot = target;
                    TreeNode* leftmin = target->right;
                    if (!leftmin) {
                        prev->right = target->left;
                    } else {
                        while (leftmin->left) {
                            prevroot = leftmin;
                            leftmin = leftmin->left;
                        }
                        if (prevroot != target) {
                            prevroot->left = leftmin->right;
                            leftmin->right = target->right;
                        }
                        prev->right = leftmin;
                        leftmin->left = target->left;
                    }
                    delete target;
                }
            }
        }
        return root;
    }
};