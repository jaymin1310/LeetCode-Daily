class Solution {
public:
    int recursion(vector<vector<int>>&grid,int row,int col1,int col2,vector<vector<vector<int>>>&dp){
        if(row>=grid.size()){
            return 0;
        }
        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
        int maxi=0;
        int currval;
        if(col1==col2){
            currval=grid[row][col1];
        }else{
            currval=grid[row][col1]+grid[row][col2];
        }
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int ncol1=col1+i;
                int ncol2=col2+j;
                if( ncol1<0 || ncol2<0 || ncol1>=grid[0].size() || ncol2>=grid[0].size())continue;
                int ans=recursion(grid,row+1,ncol1,ncol2,dp);
                maxi=max(maxi,ans);
            }
        }
        return dp[row][col1][col2]=currval+maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        return recursion(grid,0,0,col-1,dp);
    }
};