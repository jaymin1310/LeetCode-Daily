class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUpar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUpar(parent[u]);
    }
    void unionBySize(int u, int v) {
        int uu = findUpar(u);
        int uv = findUpar(v);
        // if both in same componant from initially
        if (uu == uv)
            return;
        if (size[uu] >= size[uv]) {
            parent[uv] = uu;
            size[uu] += size[uv];
        } else {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU obj=DSU(n+1);
        int ans=INT_MAX;
        for(auto &it:roads){
            obj.unionBySize(it[0],it[1]);
        }
        int mainPar=obj.findUpar(1);
        for(auto &it:roads){
            if(obj.findUpar(it[0])==mainPar){
                ans=min(it[2],ans);
            }
        }
        return ans;
    }
};