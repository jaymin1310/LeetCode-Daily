class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size(), maxlen = 0;
        unordered_map<int, int> mp;
        for (r; r < n; r++) {
            mp[nums[r]]++;
            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};