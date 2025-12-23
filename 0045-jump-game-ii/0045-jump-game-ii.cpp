class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0,n=nums.size(),end=0,jmp=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,i+nums[i]);
            if(i==end){
                jmp++;
                end=maxi;
                if (end>= n - 1) break;
            }
        }
        return jmp;
    }
};