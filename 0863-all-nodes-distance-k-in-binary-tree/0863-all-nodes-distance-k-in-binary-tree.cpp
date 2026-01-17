/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> childatKdistance(TreeNode* root,int k,TreeNode* visited){
        vector<int>temp;
        if(k==0){
            return {root->val};
        }
        if(root->left && root->left!=visited){
            vector<int> allnodes = childatKdistance(root->left, k-1,visited);
            temp.insert(temp.end(), allnodes.begin(), allnodes.end());
        }
        if(root->right && root->right!=visited){
            vector<int>allnodes=childatKdistance(root->right,k-1,visited);
            temp.insert(temp.end(),allnodes.begin(),allnodes.end());
        }
        return temp;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*>qu;
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=nullptr;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            while(size--){
                TreeNode* front=qu.front();
                qu.pop();
                if(front->left){
                    qu.push(front->left);
                    parent[front->left]=front;
                }
                if(front->right){
                    qu.push(front->right);
                    parent[front->right]=front;
                }
            }
        }
        TreeNode* tempnode=target;
        TreeNode* marked=nullptr;
        while(tempnode){
            vector<int>allnodes=childatKdistance(tempnode,k,marked);
            ans.insert(ans.end(),allnodes.begin(),allnodes.end());
            k--;
            marked=tempnode;
            tempnode=parent[tempnode];
        }
        return ans;
    }
};