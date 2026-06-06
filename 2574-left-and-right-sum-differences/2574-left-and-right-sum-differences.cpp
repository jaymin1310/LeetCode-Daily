class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int totSum=0,currSum=0;
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        for(int i=0;i<n;i++){
            int rightSum=totSum-(nums[i]+currSum);
            diff[i]=abs(rightSum-currSum);
            currSum+=nums[i];
        }
        return diff;
    }
};