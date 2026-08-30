class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int mine=0,maxe=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[maxe]){
                maxe=i;
            }else if(nums[i]<nums[mine]){
                mine=i;
            }
        } 
        cout<<mine<<" "<<maxe;
        int ans=n;
        if(mine<maxe){
            ans=min(ans,min(maxe+1,n-mine));
        }else{
            ans=min(ans,min(mine+1,n-maxe));
        }
        if(mine>=(n/2) && maxe<(n/2) || maxe>=(n/2) && mine<(n/2)){
            int diff=abs(mine-maxe)-1;
            ans=min(ans,n-diff);
        }
        return ans;
    }
};