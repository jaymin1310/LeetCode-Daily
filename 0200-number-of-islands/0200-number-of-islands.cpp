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
        vector<vector<char>>temp=grid;
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]=='1'){
                    cnt++;
                    helper(temp,i,j);
                }
            }
        }
        return cnt;
    }
};