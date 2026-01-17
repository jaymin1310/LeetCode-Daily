class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        parent[root] = root;
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

        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int dist=0;
        while (!q.empty()) {
            if(dist==k)break;
            int size=q.size();
            while(size--){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && visited.find(front->left)==visited.end()){
                    q.push(front->left);
                    visited.insert(front->left);
                }
                if(front->right&& visited.find(front->right)==visited.end()){
                    q.push(front->right);
                    visited.insert(front->right);
                }
                if( visited.find(parent[front])==visited.end()){
                    q.push(parent[front]);
                    visited.insert(parent[front]);
                }
            }
            dist++;  
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
