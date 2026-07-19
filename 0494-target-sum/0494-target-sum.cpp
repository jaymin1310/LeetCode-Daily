class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<int>dp(2*sum+1,0);
        if(target >= -sum && target <= sum)
            dp[target + sum] = 1;
        for(int i=n-1;i>=0;i--){
            vector<int>temp(2*sum+1,0);
            for(int currsum=-sum;currsum<=sum;currsum++){
                int ways=0;
                if(currsum-nums[i]>=-sum){
                    ways+=dp[currsum-nums[i]+sum];
                }
                if(currsum+nums[i]<=sum){
                    ways+=dp[currsum+nums[i]+sum];
                }
                temp[currsum+sum]=ways;
            }
            dp=temp;
        }
        return dp[sum];
    }
};