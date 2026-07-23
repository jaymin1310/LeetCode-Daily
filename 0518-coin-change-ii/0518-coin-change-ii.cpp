class Solution {
public:
    int change(int target, vector<int>& coins) {
        vector<vector<long long>>dp(coins.size(),vector<long long>(target+1,0));
        int n=coins.size();
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int take=0;
                if(j-coins[i]>=0)
                take=dp[i][j-coins[i]];
                long long nottake=dp[i-1][j];
                dp[i][j]=1LL*(take+nottake);
            }
        }
        return dp[n-1][target];
    }
};