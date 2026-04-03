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
    void union_by_size(int u,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);
        if(ult_u==ult_v)return ;
        if(size_node[ult_u]>=size_node[ult_v]){
            ult_par[ult_v]=ult_u;
            size_node[ult_u]+=size_node[ult_v];
        }else{
            ult_par[ult_u]=ult_v;
            size_node[ult_v]+=size_node[ult_u];
        }
    }
    int findparent(int u){
        if(u==ult_par[u])return u;
        return ult_par[u]=findparent(ult_par[u]);
    }
    int findsize(int u){
        return size_node[findparent(u)];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        int max_size=0;
        vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int cell0=(i*n)+j;
                    for(auto &it:dir){
                        int nrow=i+it[0];
                        int ncol=j+it[1];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]){
                            int cell1=(nrow*n)+ncol;
                            dsu.union_by_size(cell0,cell1);
                        }
                    }
                    int island_size=dsu.findsize(cell0);
                    max_size=max(max_size,island_size);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    int sum=1;
                    unordered_set<int>st;
                    for(auto &it:dir){
                        int nrow=i+it[0];
                        int ncol=j+it[1];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]){
                            int cell=(nrow*n)+ncol;
                            int parent=dsu.findparent(cell);
                            st.insert(parent);
                        }
                    }
                    for(auto &unique_par:st){
                        sum+=dsu.findsize(unique_par);
                    }
                    max_size=max(max_size,sum);
                }
            }
        }
        return max_size;
    }
};