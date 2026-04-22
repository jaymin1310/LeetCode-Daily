class Solution {
public:
    int allPaths(int i,int j,int row,int col,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==row-1 && j==col-1){
            return 1;
        }
        int path1=0,path2=0;
        if(i<row-1)
            path1=allPaths(i+1,j,row,col,dp);
        if(j<col-1)
            path2=allPaths(i,j+1,row,col,dp);
        return dp[i][j]=path1+path2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return allPaths(0,0,m,n,dp);
    }
};