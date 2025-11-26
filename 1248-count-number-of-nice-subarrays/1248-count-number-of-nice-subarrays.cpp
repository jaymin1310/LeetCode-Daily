class Solution {
public:
    int subArray(vector<int>&nums,int k){
        int n=nums.size();
        int tot=0,l=0,cnt=0;
        for(int r=0;r<n;r++){
            if(nums[r]%2){
                cnt++;
            }
            while(cnt>k){
                if(nums[l]%2){
                    cnt--;
                }
                l++;
            }
            tot+=r-l+1;
        }
        return tot;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subArray(nums,k)-subArray(nums,k-1);
    }
};