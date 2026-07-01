class Solution {
public:
    bool bsOnAns(int mid,vector<vector<int>>&dist,vector<vector<int>>&vis){
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int n=dist.size();
        queue<pair<int,int>>qu;
        qu.push({0,0});
        vis[0][0]=1;
        while(!qu.empty()){
            auto [r,c]=qu.front();
            qu.pop();
            if(r==n-1 && c==n-1)return true;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    if(dist[nr][nc]>=mid){
                        vis[nr][nc]=1;
                        qu.push({nr,nc});
                    }
                }
            }

        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> theives;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    theives.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!theives.empty()) {
            auto [r, c] = theives.front();
            theives.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    theives.push({nr, nc});
                }
            }
        }
        int low=0;
        int high=min(dist[0][0],dist[n-1][n-1]);
        while(low<=high){
            int mid=low+(high-low)/2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            bool isPos=bsOnAns(mid,dist,vis);
            if(isPos){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;

    }
};