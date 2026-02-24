class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0 || row>=m || col<0 ||col>=n || grid[row][col]!=1)return;
        grid[row][col]=-1;
        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<n;i++){
            dfs(0,i,grid);
            dfs(m-1,i,grid);
        }
        for(int i=0;i<m;i++){
            dfs(i,0,grid);
            dfs(i,n-1,grid);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){
                    grid[i][j]=1;
                }else if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};