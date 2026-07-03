class Solution {
public:
    bool isPos(vector<vector<pair<int,int>>>&neigh,vector<bool>&online,long long k,int mid){
        int n=online.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        pq.push({0,0});
        dist[0]=0;
         while(!pq.empty()){
            auto [cost,node]=pq.top();
            pq.pop();
            if (cost != dist[node]) continue; 
            if (node == n - 1) return true;
            for(auto &it:neigh[node]){
                if(!online[it.first])continue;
                if(it.second<mid)continue;
                long long newcost=cost+it.second;
                if(newcost<mid)continue;
                if(newcost<=k && newcost<dist[it.first]){
                        dist[it.first]=newcost;
                        pq.push({newcost,it.first});
                }
            }
        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        int m=edges.size();
        vector<vector<pair<int,int>>>neigh(n);
        int maxcost=INT_MIN;
        for(auto &it:edges){
            neigh[it[0]].push_back({it[1],it[2]});// ex 1->2 with cost 3
            maxcost=max(maxcost,it[2]);
        }
        int low=0,high=maxcost,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPos(neigh,online,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};