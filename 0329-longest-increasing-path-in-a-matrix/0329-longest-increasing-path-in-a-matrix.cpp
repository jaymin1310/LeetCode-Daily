class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat){
        int m=mat.size();
        int n=mat[0].size();
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        dp[i][j]=1;
        for(auto &it:dir){
            int newi=it[0]+i;
            int newj=it[1]+j;
            if(newi>=0 && newj>=0 && newi<m && newj<n && mat[newi][newj]>mat[i][j]){
                int val=dp[newi][newj]==-1 ? dfs(newi,newj,dp,mat):dp[newi][newj];
                dp[i][j]=max(dp[i][j],1+val);
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxlen=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1)
                    dp[i][j]=dfs(i,j,dp,matrix);
                maxlen=max(maxlen,dp[i][j]);
            }
        }
        return maxlen;
    }
};