class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=-1,q=-1;
        for(int i=1;i<n;i++){
            if(p==-1 && nums[i]<nums[i-1]){
                p=i-1;
            }else if(p!=-1 && nums[i]>nums[i-1]) q=i-1;
            else if(nums[i]==nums[i-1]) return false;
            else if(q!=-1 && nums[i]<nums[i-1]) return false;
        }
        return (0 < p && p < q);
    }
};