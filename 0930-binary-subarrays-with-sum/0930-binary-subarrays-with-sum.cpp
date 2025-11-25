class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0,r=0;
        int n=nums.size();
        int sum=0;
        int cnt=0,tot=0;
        while(r<=n){
            if(r!=n)sum+=nums[r];
            if((sum==goal && r==n ) || sum>goal){
                if(goal==0){
                    int i=r-l;
                    tot+=(i+1)*i/2;
                    sum-=nums[r];
                    l=r+1;
                }else{
                int dist=1;
                while(nums[l]!=1 && l<n){
                    dist++;
                    l++;
                }
                sum-=nums[l];
                l++;
                cnt=dist*cnt;
                tot+=cnt;
                cnt=0;
                }
            }
            if(sum==goal){
                cnt++;
            }
            r++;
        }
        return tot;
    }
};