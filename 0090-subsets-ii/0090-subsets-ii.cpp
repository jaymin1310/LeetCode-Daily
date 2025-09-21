class Solution {
public:
vector<vector<int>> ans;
void recursion(vector<int>&nums,vector<int>temp,int ind){
    ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            recursion(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        recursion(nums,temp,0);
        return ans;
    }
};