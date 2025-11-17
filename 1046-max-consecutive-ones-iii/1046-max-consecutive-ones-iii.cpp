class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int len=0;
        while(r<n){
            if(nums[r]==0)k--;
            if(k<0){
                if(nums[l]==0)k++;
                l++;
            }else{
                len++;
            }
            r++;
        }
        return len;
    }
};