class Solution {
public:
    bool check(vector<int>& nums) {
        int maxLeft=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(maxLeft!=-1)return false;
                maxLeft=nums[i-1];
            }
            if(maxLeft!=-1 && (nums[i]>maxLeft || nums[i]>nums[0]) )return false;
        }
        return true;
    }
};