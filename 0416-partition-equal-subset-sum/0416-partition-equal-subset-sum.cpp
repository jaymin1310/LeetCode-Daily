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
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (nums[n - 1] <= target)
            dp[n-1][nums[n - 1]] = true;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= target; j++) {
                bool take=false;
                if (nums[i] <= j)
                    take = dp[i+ 1][j - nums[i]];
                bool nottake =dp[i+ 1][j];
                dp[i][j]=take||nottake;
            }
        }
        return dp[0][target];
    }
};