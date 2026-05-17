class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int notTake=dp[j];
                int take=INT_MAX;
                if(j>=coins[i])
                    take=dp[j-coins[i]];
                if(take!=INT_MAX)take+=1;
                dp[j]=min(take,notTake);
            }
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};