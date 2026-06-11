class Solution {
public:
    static const long long MOD = 1e9 + 7;
    long long getPower(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1)
                res = (res * a) % MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>neigh(n+1);
        vector<int>vis(n+1,0);
        for(auto &it:edges){
            neigh[it[1]].push_back(it[0]);
            neigh[it[0]].push_back(it[1]);
        }
        stack<pair<int,int>>st;
        st.push({1,0});
        int depth=0;
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            vis[top.first]=1;
            depth=max(top.second,depth);
            for(auto &it:neigh[top.first]){
                if(!vis[it])
                st.push({it,top.second+1});
            }
        }
        return getPower(2,depth-1);
    }
};