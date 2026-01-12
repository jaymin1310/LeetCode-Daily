class Solution {
public:
    TreeNode* ans = NULL;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;

        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        bool mid = (root == p || root == q);

        if(mid + left + right >= 2 && !ans)
            ans = root;

        return mid || left || right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
