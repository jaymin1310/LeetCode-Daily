class Solution {
    int const r[4]={-1,1,0,0};
    int const c[4]={0,0,1,-1};
public:
    bool helper(vector<vector<int>>&grid,int health,int row,int col,vector<vector<int>>&maxhealth){
        int m=grid.size();
        int n=grid[0].size();
        if(grid[row][col]){
            health--;
            if(health<=0)return false;
        }
        if(health<=maxhealth[row][col])return false;
        maxhealth[row][col]=health;
        if(row==m-1 && col==n-1)return true;
        for(int i=0;i<4;i++){
            int nr=r[i]+row;
            int nc=c[i]+col;
            if(nr>=0 && nc>=0 && nr<m && nc<n){
                if(helper(grid,health,nr,nc,maxhealth))return true;
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>>maxhealth(grid.size(),vector<int>(grid[0].size(),0));
        return helper(grid,health,0,0,maxhealth);
    }
};