class Solution {
public:
    long long maxp; 
    long long total;

    long long sum(TreeNode* node) {
        if (node == nullptr) return 0;
        return sum(node->left) + sum(node->right) + node->val;
    }

    long long dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        auto ssum = root->val + dfs(root->left) + dfs(root->right);
        maxp = max(maxp, ssum * (total - ssum));
        return ssum;
    }

    int maxProduct(TreeNode* root) {
        maxp = 0;
        total = sum(root);
        dfs(root);
        long long MOD = 1000000007LL;
        return int(maxp % MOD);
    }
};