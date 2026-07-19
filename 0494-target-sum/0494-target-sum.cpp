class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(2*sum+1,0));
        if(target >= -sum && target <= sum)
            dp[n][target + sum] = 1;
        for(int i=n-1;i>=0;i--){
            for(int currsum=-sum;currsum<=sum;currsum++){
                int ways=0;
                if(currsum-nums[i]>=-sum){
                    ways+=dp[i+1][currsum-nums[i]+sum];
                }
                if(currsum+nums[i]<=sum){
                    ways+=dp[i+1][currsum+nums[i]+sum];
                }
                dp[i][currsum+sum]=ways;
            }
        }
        return dp[0][sum];
    }
};