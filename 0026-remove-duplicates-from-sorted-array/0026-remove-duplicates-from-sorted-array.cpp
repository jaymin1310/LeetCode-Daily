class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int i=0;
        int j=0;
        while(j<n){
            if(nums[i]!=nums[j]){
                i++;
                cnt++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        return cnt;
    }
};