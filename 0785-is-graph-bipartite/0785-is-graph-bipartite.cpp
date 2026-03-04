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
                    for(auto &it:graph[front]){
                        if(!vis[it]){
                            vis[it] = 3 - vis[front];
                            qu.push(it);
                        }
                        else if(vis[it] == vis[front]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};