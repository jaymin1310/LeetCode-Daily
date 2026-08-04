class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>miss(101,1);
        int small=INT_MAX,big=INT_MIN;
        for(int i=0;i<nums.size();i++){
            small=min(small,nums[i]);
            big=max(big,nums[i]);
            miss[nums[i]]=0;
        }
        vector<int>ans;
        for(int i=small;i<=big;i++){
            if(miss[i])ans.push_back(i);
        }
        return ans;
    }
};