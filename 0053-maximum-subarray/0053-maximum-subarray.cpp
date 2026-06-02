class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int larSum=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            larSum=max(sum,larSum);
            if(sum<0)sum=0;
        }
        return larSum;
    }
};