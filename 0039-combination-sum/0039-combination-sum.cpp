class Solution {
public:
    void recursion(vector<int>&nums,int k,vector<int>temp,vector<vector<int>>&ans,int i){
        if(k<=0||i>=nums.size()){
            if(k==0){
                ans.push_back(temp);
            }
            return ;
        }
        temp.push_back(nums[i]);
        recursion(nums,k-nums[i],temp,ans,i);
        temp.pop_back();
        recursion(nums,k,temp,ans,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        recursion(candidates,target,temp,ans,0);
        return ans;
    }
};