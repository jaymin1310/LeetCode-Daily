class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto [diff, cord] = pq.top();
            int currelem = heights[cord.first][cord.second];
            int curreffort = dist[cord.first][cord.second];
            pq.pop();
            for (auto& it : dir) {
                int nrow = cord.first + it[0];
                int ncol = cord.second + it[1];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    int diff =
                        max(abs(heights[nrow][ncol] - currelem), curreffort);
                    if (diff < dist[nrow][ncol]) {
                        dist[nrow][ncol] = diff;
                        pq.push({diff, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};