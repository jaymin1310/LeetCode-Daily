class Solution {
public:
    int findparent(int u,vector<int>&parent){
        if(u==parent[u])return u;
        return parent[u]=findparent(parent[u],parent);
    }
    int removeStones(vector<vector<int>>& stones) {
        int row=0,col=0;
        for(auto &it:stones){
            row=max(row,it[0]+1);
            col=max(col,it[1]+1);
        }
        int totalNode=row+col;
        vector<int>ult_parent(totalNode);
        vector<int>size_node(totalNode,1);
        for(int i=0;i<totalNode;i++){
            ult_parent[i]=i;
        }
        unordered_map<int,int>mp;
        for(auto &it:stones){
            int ult_u=findparent(it[0],ult_parent);
            int ult_v=findparent(it[1]+row,ult_parent);
            if(ult_u==ult_v)continue;
            if(size_node[ult_u]>=size_node[ult_v]){
                ult_parent[ult_v]=ult_u;
                size_node[ult_u]+=size_node[ult_v];
            }else{
                ult_parent[ult_u]=ult_v;
                size_node[ult_v]+=size_node[ult_u];
            }
            mp[it[0]]=1;
            mp[it[1]+row]=1;
        }
        int cnt=0;
        for(auto &it:mp){
            if(findparent(it.first,ult_parent)==it.first){
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};