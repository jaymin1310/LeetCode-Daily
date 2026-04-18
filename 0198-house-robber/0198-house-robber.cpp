class Solution {
public:
    int helper(vector<int>&nums,vector<int>&dp,int ind){
        if(ind<0)return 0;
        if(ind<2)return nums[ind];
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind-2;i>=0;i--){
            dp[ind]=max(dp[ind],nums[ind]+helper(nums,dp,i));
        }
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans1=helper(nums,dp,n-1);
        int ans2=helper(nums,dp,n-2);
        return max(ans1,ans2);
    }
};