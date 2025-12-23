class Solution {
public:
    int jump(vector<int>& nums) {
        int i=1,nexi=0,jmp=0;
        int maxi=0,n=nums.size();
        while(i<n){ 
            nexi=nums[maxi]+maxi;
            jmp++;
            if(nexi>=n-1)break;
            while(i<n && i<=nexi){
                if(i+nums[i] > maxi+nums[maxi]){
                    maxi=i;
                }
                i++;
            }
        }
        return jmp;
    }
};