class Solution {
public:
    void rotateBy90(vector<vector<int>>&grid){
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(grid[i].begin(),grid[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)return true;
        for(int i=0;i<3;i++){
            rotateBy90(mat);
            if(mat==target)return true;
        }
        return false;
    }
};