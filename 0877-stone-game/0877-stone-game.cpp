class Solution {
public:
    int helper(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
        if(i==j)return piles[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int takeLeft=piles[i]-helper(piles,i+1,j,dp);
        int takeRight=piles[j]-helper(piles,i,j-1,dp);
        return dp[i][j]=max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(piles,0,n-1,dp)>0;
    }
};