class Solution {
public:
    void helper(vector<vector<char>>&temp,int i,int j){
        int m=temp.size();
        int n=temp[0].size();
        if(i<0 || j<0 || i>=m || j>=n || temp[i][j]!='1')return;
        temp[i][j]='#';
        helper(temp,i+1,j);
        helper(temp,i,j+1);
        helper(temp,i-1,j);
        helper(temp,i,j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    helper(grid,i,j);
                }
                else if(grid[i][j]=='#')grid[i][j]='1';
            }
        }
        return cnt;
    }
};