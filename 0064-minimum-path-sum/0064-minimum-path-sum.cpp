class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up=0,left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0)left=dp[i][j-1];
                if(i==0){
                    dp[i][j]=grid[i][j]+left;
                }
                else if(j==0){
                    dp[i][j]=grid[i][j]+up;
                }
                else dp[i][j]=min(grid[i][j]+up,grid[i][j]+left);
            }
        }
        return dp[m-1][n-1];
    }
};