class Solution {
public:
    void rightShift(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); i += 2) {
            int temp = grid[i][grid[0].size()-1];
            for (int j = grid[0].size()-1; j >0; j--) {
                grid[i][j] = grid[i][j - 1];
            }
            grid[i][0] = temp;
        }
    }
    void leftShift(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i += 2) {
            int temp = grid[i][0];
            for (int j = 0; j < grid[0].size() - 1; j++) {
                grid[i][j] = grid[i][j + 1];
            }
            grid[i][grid[0].size() - 1] = temp;
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> grid = mat;
        for (int i = 0; i < k; i++) {
            leftShift(grid);
            rightShift(grid);
        }
        return (grid == mat);
    }
};