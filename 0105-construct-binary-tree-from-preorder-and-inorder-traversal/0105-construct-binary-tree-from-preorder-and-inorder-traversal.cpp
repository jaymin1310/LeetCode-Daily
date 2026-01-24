class Solution {
public:
    TreeNode* build(vector<int>& preorder, int low, int high,
                    unordered_map<int,int>& mp, int& idx) {
        if (low > high) return nullptr;

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->left = build(preorder, low, mid - 1, mp, idx);
        root->right = build(preorder, mid + 1, high, mp, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int idx = 0;
        return build(preorder, 0, inorder.size() - 1, mp, idx);
    }
};
