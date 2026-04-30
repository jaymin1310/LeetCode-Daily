class Solution {
public:
    int helper(vector<vector<int>>&grid,int k,int i,int j,vector<vector<vector<int>>>&dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n){
            return INT_MIN;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int newk=k;
        if(grid[i][j]!=0)newk--;
        if(newk<0)return dp[i][j][k]=INT_MIN;
        if(i==m-1 && j==n-1)return dp[i][j][k]=grid[i][j];
        int right=helper(grid,newk,i, j+1,dp);
        int down=helper(grid,newk, i+1,j,dp);
        int best=max(right,down);
        if(best==INT_MIN)return dp[i][j][k]=INT_MIN;
        return dp[i][j][k]=grid[i][j]+best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        int ans=helper(grid,k,0,0,dp);
        if(ans==INT_MIN)return -1;
        return ans;
    }
};