class Solution {
public:
    vector<int> bit;

    void add(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        bit.assign(2 * n + 3, 0);

        int cnt = 0;
        long long ans = 0;

        add(n + 1, 1); 

        for (int x : nums) {
            if (x == target) cnt++;
            else cnt--;

            int idx = cnt + n + 1;

            ans += sum(idx - 1);  

            add(idx, 1);
        }

        return ans;
    }
};