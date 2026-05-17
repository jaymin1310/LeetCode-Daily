class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        for(int i=n-1;i>=0;i--){
            dp[i][0]=0;
            for(int j=1;j<=amount;j++){
                int notTake=dp[i+1][j];
                int take=INT_MAX;
                if(j>=coins[i])
                    take=dp[i][j-coins[i]];
                if(take!=INT_MAX)take+=1;
                dp[i][j]=min(take,notTake);
            }
        }
        return (dp[0][amount]==INT_MAX)?-1:dp[0][amount];
    }
};