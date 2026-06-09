class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minele=INT_MAX;
        int maxele=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minele=min(minele,nums[i]);
            maxele=max(maxele,nums[i]);
        }
        int diff=maxele-minele;
        long long ans=1LL * k * diff;
        return ans;
    }
};