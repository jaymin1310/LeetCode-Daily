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
        if (size[uu] > size[uv]) {
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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, pair<int, int>>> data;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                data.push_back({grid[i][j], {i, j}});
            }
        }
        sort(data.begin(), data.end());
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        DSU dsu(n * n);
        for (auto& el : data) {
            int ele = el.first;
            auto [row, col] = el.second;
            int current = row * n + col;
            for (auto& it : dir) {
                int nrow = it[0] + row;
                int ncol = it[1] + col;
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n)
                    continue;
                if (grid[nrow][ncol] < ele) {
                    dsu.unionBySize(nrow * n + ncol, current);
                }
            }
            if (dsu.findUpar(n * n - 1) == dsu.findUpar(0)) {
                return ele;
            }
        }

        return -1;
    }
};