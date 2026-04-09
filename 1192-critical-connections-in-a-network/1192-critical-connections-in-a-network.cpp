class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<int> &tin, vector<int>& low,
             vector<vector<int>>& adj, vector<int>& vis,
             vector<vector<int>>& ans) {
        vis[node] = 1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for (auto& it : adj[node]) {
            if (it == parent)
                continue;
            if (vis[it]) {
                low[node] = min(low[node], low[it]);
            } else {
                dfs(it, node, tin, low, adj, vis,ans);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) {
                    ans.push_back({it, node});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for (auto& it : conn) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>tin(n,-1);
        vector<int>low(n,-1);
        vector<vector<int>> ans;
        dfs(0, -1, tin, low, adj, vis, ans);
        return ans;
    }
};