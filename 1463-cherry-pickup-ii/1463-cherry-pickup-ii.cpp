class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(
            row, vector<vector<int>>(col, vector<int>(col, 0)));
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) {
                if (i == j)
                    dp[row - 1][i][j] = grid[row - 1][i];
                else
                    dp[row - 1][i][j] = grid[row - 1][i] + grid[row - 1][j];
            }
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; k++) {
                    int value;
                    if (j == k)
                        value = grid[i][j];
                    else
                        value = grid[i][j] + grid[i][k];
                    int maxi = 0;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int ncol1 = j + dj1;
                            int ncol2 = k + dj2;
                            if (ncol1 >= 0 && ncol2 >= 0 && ncol1 < col &&
                                ncol2 < col) {
                                maxi = max(maxi, dp[i + 1][ncol1][ncol2]);
                            }
                        }
                    }
                    dp[i][j][k] = value + maxi;
                }
            }
        }
        return dp[0][0][col-1];
    }
};