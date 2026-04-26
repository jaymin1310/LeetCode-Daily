class Solution {
public:
    bool dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,pair<int,int>par){
        pair<int,int>newpar={i,j};
        if(vis[i][j])return true;
        vis[i][j]=1;
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        for(auto &it:dir){
            int nrow=i+it[0];
            int ncol=j+it[1];
            pair<int,int>temppar={nrow,ncol};
            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && par!=temppar && grid[nrow][ncol]==grid[i][j]){
                if(dfs(grid,vis,nrow,ncol,newpar)){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]){
                    if(dfs(grid,vis,i,j,{-1,-1}))return true;
                }
            }
        }
        return false;
    }
};