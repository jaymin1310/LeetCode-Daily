class Solution {
public:
    int findparent(int u,vector<int>&par){
        if(u==par[u])return u;
        return par[u]=findparent(par[u],par);
    }
    int makeConnected(int n, vector<vector<int>>& connection) {
        if(connection.size()<n-1)return -1;
        vector<int>ult_par(n);
        vector<int>size_node(n,1);
        for(int i=0;i<n;i++){
            ult_par[i]=i;
        }
        int cnt=0;
        for(auto &it:connection){
            int ult_u=findparent(it[0],ult_par);
            int ult_v=findparent(it[1],ult_par);
            if(ult_u==ult_v)continue;
            if(size_node[ult_u]>=size_node[ult_v]){
                size_node[ult_u]+=size_node[ult_v];
                ult_par[ult_v]=ult_u;
            }else{
                size_node[ult_v]+=size_node[ult_u];
                ult_par[ult_u]=ult_v;
            }
            cnt++;
        }
        return (n-1)-cnt;
    }
};