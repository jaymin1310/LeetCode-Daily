class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(auto &it:nums){
            total+=it;
        }
        int preval=0;
        for(int i=0;i<n;i++){
            preval+=(i*nums[i]);
        }
        int ans=preval;
        for(int i=1;i<n;i++){
            int newval=preval+total-(n*nums[n-i]);
            preval=newval;
            ans=max(ans,newval);
        }
        return ans;
    }
};