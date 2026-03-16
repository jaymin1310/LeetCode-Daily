class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>timetaken(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        timetaken[k]=0;
        while(!pq.empty()){
            auto [time,node]=pq.top();
            pq.pop();
            if(time>timetaken[node])continue;
            for(auto &it:adj[node]){
                int ntime=it.second+time;
                if(ntime<timetaken[it.first]){
                    timetaken[it.first]=ntime;
                    pq.push({ntime,it.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans = max(ans,timetaken[i]);
        }
        return (ans==1e9)?-1:ans;
    }
};