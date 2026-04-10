class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>ind;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            ind[nums[i]].push_back(i);
            if(ind[nums[i]].size()==3){
                ans=min(ans,2*(ind[nums[i]][2]-ind[nums[i]][0]));
                ind[nums[i]].erase(ind[nums[i]].begin());
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};