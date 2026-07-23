class Solution {
public:
    int helper(int amt,vector<int>&coins,int i,vector<vector<int>>&dp){
        if(i==coins.size()){
            return amt==0?1:0;
        }
        if(amt<0)return 0;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int take=helper(amt-coins[i],coins,i,dp);
        int nottake=helper(amt,coins,i+1,dp);
        return dp[i][amt]=take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return helper(amount,coins,0,dp);
    }
};