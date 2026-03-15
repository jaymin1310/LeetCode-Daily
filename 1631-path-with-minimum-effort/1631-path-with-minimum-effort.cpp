class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid, int mid,
             vector<vector<int>>& vis) {

        int m = grid.size();
        int n = grid[0].size();

        if (row == m - 1 && col == n - 1)
            return true;

        vis[row][col] = 1;

        int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for (auto& d : dir) {

            int nr = row + d[0];
            int nc = col + d[1];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc]) {

                if (abs(grid[row][col] - grid[nr][nc]) <= mid) {

                    if (dfs(nr, nc, grid, mid, vis))
                        return true;
                }
            }
        }

        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {

        int low = 0, high = 1e6;

        while (low <= high) {

            int mid = (low + high) / 2;

            vector<vector<int>> vis(heights.size(),
                                    vector<int>(heights[0].size(), 0));

            if (dfs(0, 0, heights, mid, vis))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};