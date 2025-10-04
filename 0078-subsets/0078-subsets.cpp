class Solution {
public:
    vector<vector<int>>ans;
     void recursionString(string current,int n,vector<int>&nums){
        if(n<=1){
            vector<int>temp;
            for(int i=0;i<nums.size();i++){
                if(current[i]=='1'){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
            return;
        }
        recursionString(current+'0',n-1,nums);
        recursionString(current+'1',n-1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        recursionString("0",n,nums);
        recursionString("1",n,nums);
        return ans;
    }
};