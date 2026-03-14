class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1])return -1;
        queue<pair<int,int>>qu;
        vector<int>vis(n*n);
        qu.push({0,0});
        vis[0]=1;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        int cnt=1;
        while(!qu.empty()){
            int size=qu.size();
            while(size--){
                auto front=qu.front();
                if(front.first==n-1 && front.second==n-1)return cnt;
                qu.pop();
                for(auto &it:dir){
                    int x=it[0]+front.first;
                    int y=it[1]+front.second;
                    if(x<0 || x>=n || y<0 || y>=n)continue;
                    if(grid[x][y]==0 && !vis[x*n+y]){
                        vis[(x*n)+y]=1;
                        qu.push({x,y});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};