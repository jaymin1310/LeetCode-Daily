class Solution {
public:
    bool check(vector<int>& nums) {
        int maxLeft=-1;
        int smallLeft=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(maxLeft!=-1)return false;
                maxLeft=nums[i-1];
            }
            if(maxLeft!=-1 && (nums[i]>maxLeft || nums[i]>smallLeft) )return false;
        }
        return true;
    }
};