class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int total=0;
        for(auto &it:nums){
            total+=it;
        }
        for(int i=0;i<n;i++){
            dp[i]=total-nums[i];
        }
        int preval=0;
        for(int i=0;i<n;i++){
            preval+=(i*nums[i]);
        }
        int ans=preval;
        for(int i=1;i<n;i++){
            int newval=preval-((n-1)*nums[n-i])+dp[n-i];
            preval=newval;
            ans=max(ans,newval);
        }
        return ans;
    }
};