class Solution {
public:
    vector<int> childatKdistance(TreeNode* root, int k, TreeNode* blocked) {
        if (!root || k < 0) return {};
        if (k == 0) return {root->val};

        vector<int> temp;

        if (root->left && root->left != blocked) {
            auto left = childatKdistance(root->left, k - 1, blocked);
            temp.insert(temp.end(), left.begin(), left.end());
        }

        if (root->right && root->right != blocked) {
            auto right = childatKdistance(root->right, k - 1, blocked);
            temp.insert(temp.end(), right.begin(), right.end());
        }

        return temp;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        parent[root] = nullptr;
        q.push(root);

        // Mark parents
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();

            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }

        vector<int> ans;
        TreeNode* curr = target;
        TreeNode* blocked = nullptr;

        while (curr) {
            auto nodes = childatKdistance(curr, k, blocked);
            ans.insert(ans.end(), nodes.begin(), nodes.end());

            blocked = curr;
            curr = parent[curr];
            k--;
        }

        return ans;
    }
};
