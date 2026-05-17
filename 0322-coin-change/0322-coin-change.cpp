class Solution {
public:
    int helper(vector<int>& coins,int amt,vector<int>&dp){
        if(amt==0)return 0;
        if(dp[amt]!=-2)return dp[amt];
        int res=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amt){
                //take
                int temp=helper(coins,amt-coins[i],dp);
                if(temp!=-1)
                    res=min(temp+1,res);
            }
        }
        if(res==INT_MAX)return dp[amt]=-1;
        return dp[amt]=res;

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-2);
        return helper(coins,amount,dp);
    }
};