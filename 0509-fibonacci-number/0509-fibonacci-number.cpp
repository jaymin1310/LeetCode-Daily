class Solution {
public:
    int dpsol(int n,vector<int>&dp){
        if(dp[n]!=-1)return dp[n];
        if(n<=1)return dp[n]=n;
        dp[n]=dpsol(n-1,dp)+dpsol(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return dpsol(n,dp);
    }
};