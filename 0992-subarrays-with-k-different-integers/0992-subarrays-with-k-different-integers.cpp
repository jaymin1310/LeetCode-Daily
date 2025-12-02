class Solution {
public:
    int subarrayWithK(vector<int>&nums,int k){
        int n=nums.size();
        int ans=0,l=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }
            ans+=i-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithK(nums,k)-subarrayWithK(nums,k-1);
    }
};