class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int,int>> qu;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    qu.push({i, j});
                } else {
                    ans[i][j] = -1;
                }
            }
        }
        
        while(!qu.empty()){
            auto q = qu.front();
            qu.pop();
            
            int i = q.first;
            int j = q.second;
            int curr = ans[i][j];
            
            if(i + 1 < m && ans[i+1][j] == -1){
                ans[i+1][j] = curr + 1;
                qu.push({i+1, j});
            }
            if(i - 1 >= 0 && ans[i-1][j] == -1){
                ans[i-1][j] = curr + 1;
                qu.push({i-1, j});
            }
            if(j + 1 < n && ans[i][j+1] == -1){
                ans[i][j+1] = curr + 1;
                qu.push({i, j+1});
            }
            if(j - 1 >= 0 && ans[i][j-1] == -1){
                ans[i][j-1] = curr + 1;
                qu.push({i, j-1});
            }
        }
        
        return ans;
    }
};