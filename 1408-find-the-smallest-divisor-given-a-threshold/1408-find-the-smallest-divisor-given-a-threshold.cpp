class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        //agge min milega
        int l=1,h=*max_element(nums.begin(),nums.end()),mid;
        int sum=0,ans=0;
        while(l<=h){
            mid=l+(h-l)/2;
            sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=th){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};