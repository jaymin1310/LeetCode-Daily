class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edg) {
        vector<vector<int>> adj(n);

        for (auto &it : edg) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> suspicious(n, 0);
        stack<int> st;

        st.push(k);
        suspicious[k] = 1;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    st.push(v);
                }
            }
        }

        for (auto &it : edg) {
            int u = it[0];
            int v = it[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans(n);
                for (int i = 0; i < n; i++) {
                    ans[i] = i;
                }
                return ans;
            }
        }
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};