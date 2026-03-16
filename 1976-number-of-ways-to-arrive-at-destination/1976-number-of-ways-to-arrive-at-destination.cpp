class Solution {
    int const MOD=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<pair<long long,long long>>timetaken(n);
        for(auto &p :timetaken) p.first = LLONG_MAX;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        timetaken[0]={0,1};
        while(!pq.empty()){
            auto [time,city]=pq.top();
            pq.pop();
            if(time>timetaken[city].first)continue;
            for(auto &[neighcity,timetoreach]:adj[city]){
                long long ntime=time+timetoreach;
                if(ntime==timetaken[neighcity].first){
                    timetaken[neighcity].second=(timetaken[neighcity].second+timetaken[city].second)%MOD;
                }
                else if(ntime<timetaken[neighcity].first){
                    timetaken[neighcity]={ntime,timetaken[city].second};
                    pq.push({ntime,neighcity});
                }
            }
        }
        return timetaken[n-1].second%MOD;
    }
};