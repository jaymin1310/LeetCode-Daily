class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int moves=0,minEl=INT_MAX;
        for(int i=0;i<n;i++){
            minEl=min(nums[i],minEl);
        }
        for(int i=0;i<n;i++){
            moves+=nums[i]-minEl;
        }
        return moves;
    }
};