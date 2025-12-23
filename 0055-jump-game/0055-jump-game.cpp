class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int sum=0,i=0,nexi=nums[0];
        i++;
        if(nexi>=n-1)return true;
        while(i<n){ 
            int maxi=0,curmax=0;
            while(i<n && i<=nexi){
                if(i+nums[i] > curmax){
                    curmax=i+nums[i];
                    maxi=i;
                }
                i++;
            }
            if(maxi>=n-1)return true;
            if(maxi+nums[maxi]<=nexi)return false;
            nexi=maxi+nums[maxi];
        }
        return true;
    }
};