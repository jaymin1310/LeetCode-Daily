class Solution {
    int const r[4] = {-1, 1, 0, 0};
    int const c[4] = {0, 0, 1, -1};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            qu;
        qu.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while (!qu.empty()) {
            auto [dmg, cell] = qu.top();
            auto [row, col] = cell;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r[i] + row;
                int nc = c[i] + col;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    if (dist[nr][nc] > dmg + grid[nr][nc]) {
                        dist[nr][nc] = dmg + grid[nr][nc];
                        qu.push({dist[nr][nc],{nr, nc}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};