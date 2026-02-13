class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>qu;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int v=i*n+j;
                if(grid[i][j]==2)qu.push({i,j});
                else if(grid[i][j]==1)cnt++;
            }
        }
        int minute=0;
        while(!qu.empty()){
            int size=qu.size();
            bool rottedThisMinute = false;
            while(size--){
                auto it=qu.front();
                qu.pop();
                int i=it.first,j=it.second;
                if(j+1<n && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    qu.push({i,j+1});
                    cnt--;
                    rottedThisMinute = true;
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    qu.push({i,j-1});
                    cnt--;
                    rottedThisMinute = true;
                }
                if(i+1<m && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    qu.push({i+1,j});
                    cnt--;
                    rottedThisMinute = true;
                }
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    qu.push({i-1,j});
                    cnt--;
                    rottedThisMinute = true;
                }
            }
            if(rottedThisMinute)
                minute++;

        }
        return (!cnt)?minute:-1;
    }
};