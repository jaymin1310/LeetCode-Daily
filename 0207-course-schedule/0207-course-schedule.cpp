class Solution {
public:
    bool DFShelper(vector<vector<int>>& adj, vector<int>& vis, int top) {
        if (vis[top] == 1)
            return false;
        if (vis[top] == 2)
            return true;
        vis[top] = 1;
        for (auto neig : adj[top]) {
            if (!DFShelper(adj, vis, neig))
                return false;
        }
        vis[top] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto it : prereq) {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!DFShelper(adj, vis, i))
                    return false;
            }
        }
        return true;
    }
};
