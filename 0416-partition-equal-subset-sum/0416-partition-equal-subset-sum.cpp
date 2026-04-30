class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totsum += nums[i];
        }
        if (totsum % 2 != 0)
            return false;
        int target = totsum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = target; j >0; j--) {
                bool take=false;
                if (nums[i] <= j)
                    take = dp[j - nums[i]];
                bool nottake =dp[j];
                dp[j]=take||nottake;
            }
        }
        return dp[target];
    }
};