class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>qu;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        qu.push({src,0});
        int stop=0;
        while(!qu.empty()&& stop<=k){
            int size=qu.size();
            //vector<int>temp=dist;
            while(size--){
                auto [node,currCost]=qu.front();
                qu.pop();
                for(auto &&[next,price]:adj[node]){
                    if((currCost+price)<dist[next]){
                        dist[next]=currCost+price;
                        qu.push({next,currCost+price});
                    }
                }
            }
            //dist=temp;
            stop++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};