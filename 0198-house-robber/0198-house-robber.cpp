class Solution {
public:
    // int helper(vector<int>&nums,vector<int>&dp,int i){
    //     if(i<0)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     return dp[i]=max(nums[i]+helper(nums,dp,i-2),helper(nums,dp,i-1));
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0,prev2=0;
        for(int i=0;i<n;i++){
            int curr=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};