class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        if(obs[0][0])return 0;
        int m=obs.size();
        int n=obs[0].size();
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=0;i<m;i++){
            int left=0;
            for(int j=0;j<n;j++){
                if(obs[i][j]==1){
                    dp[j]=0;
                    left=0;
                    continue;
                }
                dp[j]+=left;
                left=dp[j];
            }
        }
        return dp[n-1];
    }
};