class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int small = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            small = min(small, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return gcd(small,maxi);
    }

};