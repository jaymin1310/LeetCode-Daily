class Solution {
public:
    int helper(vector<int>&arr,int d,int ind,vector<int>&dp){
        if(dp[ind]!=-1)return dp[ind];
        int maxMove=1;
        for(int i=ind+1;i<=ind+d && i<arr.size();i++){
            if(arr[i] >= arr[ind]) break;
            int move=1+helper(arr,d,i,dp);
            maxMove=max(maxMove,move);
        }
        for(int i=ind-1;i>=ind-d && i>=0;i--){
            if(arr[i]>=arr[ind])break;
            int move=1+helper(arr,d,i,dp);
            maxMove=max(maxMove,move);
        }
        return dp[ind]=maxMove;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;
        int n=arr.size();
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,helper(arr,d,i,dp));
        }
        return ans;
    }
};