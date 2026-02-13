class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>adj(m*n);
        vector<int>visited(m*n,0);
        queue<int>qu;
        int cnt=0;
        int isOrange=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int v=i*n+j;
                if(grid[i][j]==2)qu.push(v);
                else if(grid[i][j]==0)continue;
                if(j+1<n && grid[i][j+1])adj[v].push_back(v+1);
                if(j-1>=0 && grid[i][j-1])adj[v].push_back(v-1);
                if(i-1>=0 && grid[i-1][j])adj[v].push_back(v-n);
                if(i+1<m && grid[i+1][j])adj[v].push_back(v+n);
                isOrange=1;
                cnt++;
            }
        }
        if(!isOrange)return 0;
        int minute=-1;
        while(!qu.empty()){
            int size=qu.size();
            int flag=0;
            while(size--){
                int front=qu.front();
                qu.pop();
                if(visited[front])continue;
                visited[front]=1;
                for(auto it:adj[front]){
                    qu.push(it);
                }
                flag=1;
                cnt--;
            }
            if(flag==1)minute++;
        }
        return (!cnt)?minute:-1;
    }
};