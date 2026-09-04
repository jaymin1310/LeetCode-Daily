class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefMax(n);
        prefMax[0]=nums[0];
        for(int i=1;i<n;i++){
            prefMax[i]=max(prefMax[i-1],nums[i]);
        }
        int minel=INT_MAX,ans=-1;
        for(int i=n-1;i>=0;i--){
            minel=min(minel,nums[i]);
            if((prefMax[i]-minel)<=k){
                ans=i;
            }
        }
        return ans;
    }
};