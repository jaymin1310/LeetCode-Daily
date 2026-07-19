class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Impossible cases
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0)
            return 0;

        int K = (totalSum + target) / 2;
        int n = nums.size();

        vector<int> dp(K + 1, 0);

        // Base case
        if (nums[0] == 0)
            dp[0] = 2;          // +0 and -0
        else {
            dp[0] = 1;
            if (nums[0] <= K)
                dp[nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(K + 1, 0);

            for (int sum = 0; sum <= K; sum++) {
                int notTake = dp[sum];
                int take = 0;

                if (nums[i] <= sum)
                    take = dp[sum - nums[i]];

                curr[sum] = take + notTake;
            }

            dp = curr;
        }

        return dp[K];
    }
};