class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,1e9);
        dp[0]=grid[0][0];
        for(int j=1;j<n;j++){
            dp[j]=grid[0][j]+dp[j-1];
        }
        for(int i=1;i<m;i++){
            int left=1e9;
            for(int j=0;j<n;j++){
                dp[j]=min(dp[j]+grid[i][j],left+grid[i][j]);
                left=dp[j];
            }
        }
        return dp[n-1];
    }
};