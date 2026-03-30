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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int ind = 0;
        unordered_map<string, int> mail_ind;
        unordered_map<string, string> mapto_name;
        vector<string> indexToEmail;
        for (auto& it : accounts) {
            for (int i = 1; i < it.size(); i++) {
                if (mail_ind.find(it[i]) == mail_ind.end()) {
                    mail_ind[it[i]] = ind++;
                    indexToEmail.push_back(it[i]);
                    mapto_name[it[i]] = it[0];
                }
            }
        }
        int n = mail_ind.size();
        DSU obj =DSU(n);
        for (auto& it : accounts) {
            int ind_u = mail_ind[it[1]];
            for (int i = 2; i < it.size() ; i++) {
                obj.unionBySize(ind_u, mail_ind[it[i]]);
            }
        }
        unordered_map<int, vector<string>> group;
        for (int i = 0; i < n; i++) {
            int ult_par = obj.findUpar(i);
            group[ult_par].push_back(indexToEmail[i]);
        }
        vector<vector<string>> ans;
        for (auto &it:group) {
            auto &emails=it.second;
            string name = mapto_name[it.second[0]];
            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(mapto_name[emails[0]]);
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }
        return ans;
    }
};