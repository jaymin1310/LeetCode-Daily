class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        long long totSum = 0;
        for (auto& it : nums) {
            totSum += it;
        }
        vector<vector<int>> left(n + 1), right(n + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            long long sum1 = 0, sum2 = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    cnt++;
                    sum1 += nums[j];
                    sum2 += nums[n + j];
                }
            }
            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }
        for (int k = 0; k <= n; k++) {
            sort(right[k].begin(), right[k].end());
        }
        int ans = INT_MAX;
        for (int k = 0; k <= n; k++) {
            auto& L = left[k];
            auto& R = right[n - k];
            for (auto& x : L) {
                long long target = (totSum / 2) - x;
                auto it = lower_bound(R.begin(), R.end(), target);
                if (it != R.end()) {
                    long long y = *it;
                    long long S = x + y;
                    ans = min(ans,(int) abs(totSum - 2 * S));
                }
                if (it != R.begin()) {
                    it--;
                    long long y = *it;
                    long long S = x + y;
                    ans = min(ans,(int) abs(totSum - 2 * S));
                }
            }
        }
        return ans;
    }
};