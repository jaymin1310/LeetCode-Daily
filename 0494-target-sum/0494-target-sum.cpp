class Solution {
public:
    int helper(vector<int>&nums,int target,int currSum,int i,vector<vector<int>>&dp,int sum){
        if(i==nums.size()){
            if(target==currSum)return 1;
            return 0;
        }
        if(dp[i][sum+currSum]!=-1)return dp[i][sum+currSum];
        int cnt=0;
        cnt+=helper(nums,target,currSum-nums[i],i+1,dp,sum);
        cnt+=helper(nums,target,currSum+nums[i],i+1,dp,sum);
        return dp[i][sum+currSum]=cnt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return helper(nums,target,0,0,dp,sum);
    }
};