class Solution {
    int const dr[4] = {-1, 1, 0, 0};
    int const dc[4] = {0, 0, 1, -1};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newDamage = dist[row][col] + grid[nr][nc];

                    if (newDamage < dist[nr][nc]) {
                        dist[nr][nc] = newDamage;

                        if (grid[nr][nc] == 0)
                            dq.push_front({nr, nc}); // cost 0
                        else
                            dq.push_back({nr, nc});  // cost 1
                    }
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};