class Solution {
public:
void recursion(vector<vector<int>>&ans,vector<int>&nums,vector<int>temp,int ind,int target){
    if(target==0){
        ans.push_back(temp);
        return;
    }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            if(nums[i]>target)break;
            temp.push_back(nums[i]);
            recursion(ans,nums,temp,i+1,target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        recursion(ans,nums,temp,0,target);
        return ans;
    }
};