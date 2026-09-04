class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefMin(n);
        prefMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefMin[i]=min(prefMin[i+1],nums[i]);
        }
        int maxel=INT_MIN;
        for(int i=0;i<n;i++){
            maxel=max(maxel,nums[i]);
            if((maxel-prefMin[i])<=k){
                return i;
            }
        }
        return -1;
    }
};