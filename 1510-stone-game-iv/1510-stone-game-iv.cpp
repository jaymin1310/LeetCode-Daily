class Solution {
public:
    bool isPos(int n,int rem,vector<int>&dp){
        if(rem==0)return false;
        if(dp[rem]!=-1)return dp[rem];
        for(int i=1;i*i<=rem;i++){
            int sq=i*i;
            if(!isPos(n,rem-sq,dp))
                return dp[rem]=true;
        }
        return dp[rem]=false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return isPos(n,n,dp);
    }
};