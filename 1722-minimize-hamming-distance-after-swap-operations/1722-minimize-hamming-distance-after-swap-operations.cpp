class DSU{
    vector<int>ult_par;
    vector<int>size_node;
    public:
    DSU(int n){
        ult_par.resize(n);
        size_node.resize(n,1);
        for(int i=0;i<n;i++){
            ult_par[i]=i;
        }
    }
    void unionbysize(int u,int v){
        int ult_u=findultpar(u);
        int ult_v=findultpar(v);
        if(ult_u==ult_v)return ;
        if(size_node[ult_u]>=size_node[ult_v]){
            ult_par[ult_v]=ult_u;
            size_node[ult_u]+=size_node[ult_v];
        }else{
            ult_par[ult_u]=ult_v;
            size_node[ult_v]+=size_node[ult_u];
        }
    }
    int findultpar(int u){
        if(u==ult_par[u])return u;
        return ult_par[u]=findultpar(ult_par[u]);
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DSU dsu(n);
        for(auto &it:allowedSwaps){
            dsu.unionbysize(it[0],it[1]);
        }
        unordered_map<int,unordered_map<int,int>>group_map;
        for(int i=0;i<n;i++){
            int ult_par=dsu.findultpar(i);
            group_map[ult_par][source[i]]++;
        }
        int mismatch=0;
        for(int i=0;i<n;i++){
            int ult_par=dsu.findultpar(i);
            if(group_map[ult_par][target[i]]>0){
                group_map[ult_par][target[i]]--;
            }else{
                mismatch++;
            }
        }
        return mismatch;
    }
};