class Solution {
public:
    bool DFShelper(vector<vector<int>>& adj, vector<int>& vis, int top,vector<int>&res) {
        if (vis[top] == 1)
            return false;
        if (vis[top] == 2)
            return true;
        vis[top] = 1;
        for (auto neig : adj[top]) {
            if (!DFShelper(adj, vis, neig,res))
                return false;
        }
        vis[top] = 2;
        res.push_back(top);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int>ans;
        for (auto it : prereq) {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                vector<int>temp;
                if (!DFShelper(adj, vis, i,temp))
                    return {};
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
        }
        return ans;
    }
};