class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int totXor=0;
        bool hasNonZero=false;
        for(int i=0;i<n;i++){
            totXor^=nums[i];
            if(nums[i]!=0){
                hasNonZero=true;
            }

        }
        if(totXor!=0)return n;
        if(hasNonZero)return n-1;
        return 0;
    }
};