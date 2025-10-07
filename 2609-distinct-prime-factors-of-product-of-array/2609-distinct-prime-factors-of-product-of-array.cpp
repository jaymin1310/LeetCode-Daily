class Solution {
public:
    void helper(int N, unordered_set<int>& ans, vector<int>& spf) {
        while (N != 1) {
            ans.insert(spf[N]);
            N /= spf[N];
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        int maxN = *max_element(nums.begin(), nums.end());
        vector<int> spf(maxN + 1, 1);
        for (int i = 2; i <= maxN; i++) {
            if (spf[i] == 1) {
                spf[i] = i;
                for (int j = i * i; j <= maxN; j += i)
                    spf[j] = i;
            }
        }
        unordered_set<int> ans;
        for (int num : nums)
            helper(num, ans, spf);
        return ans.size();
    }
};
