class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int>qu;
                qu.push(i);
                vis[i]=1;
                while(!qu.empty()){
                    int front=qu.front();
                    qu.pop();
                    int gp1=(vis[front]==1)?1:0;
                    for(auto &it:graph[front]){
                        if(!vis[it])qu.push(it);
                        if(gp1){
                            if(vis[it]==1)return false;
                            vis[it]=2;
                        }else{
                            if(vis[it]==2)return false;
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return true;
    }
};