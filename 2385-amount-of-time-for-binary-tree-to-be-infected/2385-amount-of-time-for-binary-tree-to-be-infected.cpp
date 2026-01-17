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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> qu;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root]=root;
        qu.push(root);
        TreeNode* target = nullptr;
        while (!qu.empty()) {
            TreeNode* front = qu.front();
            qu.pop();
            if (start == front->val)
                target = front;
            if (front->left) {
                parent[front->left] = front;
                qu.push(front->left);
            }
            if (front->right) {
                parent[front->right] = front;
                qu.push(front->right);
            }
        }
        unordered_set<TreeNode*> visited;
        qu.push(target);
        visited.insert(target);
        int time = -1;
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                TreeNode* front = qu.front();
                qu.pop();
                if (front->left && visited.find(front->left) == visited.end()) {
                    visited.insert(front->left);
                    qu.push(front->left);
                }
                if (front->right &&
                    visited.find(front->right) == visited.end()) {
                    visited.insert(front->right);
                    qu.push(front->right);
                }
                if (visited.find(parent[front]) == visited.end()) {
                    visited.insert(parent[front]);
                    qu.push(parent[front]);
                }
            }
            time++;
        }
        return time;
    }
};