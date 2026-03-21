class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=y;j<(y+k);j++){
            int lastRow=x+k-1;
            for(int i=x;i<(x+(k/2));i++){
                swap(grid[i][j],grid[lastRow][j]);
                lastRow--;
            }
        }
        return grid;
    }
};