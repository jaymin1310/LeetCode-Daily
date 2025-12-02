class Solution {
public:
    int subarrayWithK(vector<int>&nums,int k){
        int n=nums.size();
        int ans=0,l=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if (mp[nums[i]] == 0) {
                k--;
            }
            mp[nums[i]]++;
            while(k<0){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    k++;
                }
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithK(nums,k)-subarrayWithK(nums,k-1);
    }
};