class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjmat(n,vector<int>(n,INT_MAX));
        vector<int>neigh(n,0);
        for(int i=0;i<n;i++){
            adjmat[i][i]=0;
        }
        for(auto &it:edges){
            adjmat[it[0]][it[1]]=it[2];
            adjmat[it[1]][it[0]]=it[2];
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int dist1=adjmat[i][via];
                    int dist2=adjmat[via][j];
                    if(dist1==INT_MAX || dist2==INT_MAX)continue;
                    if(adjmat[i][j]>(dist1+dist2))
                        adjmat[i][j]=adjmat[j][i]=dist1+dist2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjmat[i][j]<=distanceThreshold){
                       neigh[i]++;
                       neigh[j]++;
                    }
            }
        }
        int minCities=INT_MAX,city=-1;
        for(int i=0;i<n;i++){
            if(neigh[i]<=minCities){
                city=i;
                minCities=neigh[i];
            }
        }
        return city;
    }
};