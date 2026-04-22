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
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0][0]=1;
                    continue;
                }
                int up=0,left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
       // return allPaths(0,0,m,n,dp);
    }
};