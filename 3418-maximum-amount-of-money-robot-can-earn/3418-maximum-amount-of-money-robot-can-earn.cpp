class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        function<int(int, int, int)> dfs = [&](int i, int j, int k) {
            if (i >= n || j >= m)
                return INT_MIN;
            if (i == n - 1 && j == m - 1) {
                if (coins[i][j] < 0 && k > 0)
                    return 0;
                return coins[i][j];
            }
            if (dp[i][j][k] != INT_MIN)
                return dp[i][j][k];
            int take = coins[i][j] + max(dfs(i + 1, j, k), dfs(i, j + 1, k));
            int skip = INT_MIN;
            if (k > 0)
                skip = max(dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1));
            return dp[i][j][k] = max(take, skip);
        };
        return dfs(0, 0, 2);
    }
};