class Solution {
public:
void recursion(vector<vector<int>>&ans,vector<int>&nums,vector<int>temp,int ind){
    ans.push_back(temp);
    if(ind>=nums.size()){
        return;
    }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            recursion(ans,nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        recursion(ans,nums,temp,0);
        return ans;
    }
};