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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root)return -1;
        int ans1=kthSmallest(root->left,k);
        if(ans1==-1){;
        k--;
        if(k==0)return root->val;
        }else{
            return ans1;
        }
        int ans2=kthSmallest(root->right,k);
        if(ans2==-1){;
            return -1;
        }else{
            return ans2;
        }
        
    }
};