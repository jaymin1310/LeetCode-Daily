class Solution {
public:
    bool helper(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {
        if (sum == 0)
            return true;
        if (ind >= nums.size()) {
            return false;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        bool take = false;
        if (nums[ind] <= sum)
            take = helper(nums, ind + 1, sum - nums[ind], dp);
        bool nottake = helper(nums, ind + 1, sum, dp);
        return dp[ind][sum] = (take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totsum += nums[i];
        }
        if (totsum % 2 != 0)
            return false;
        int target = totsum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(nums, 0, target, dp);
    }
};