class Solution {
public:
    int checksum(vector<int>&arr,int div,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]+div-1)/div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int max=*max_element(nums.begin(),nums.end());
        int low=1,high=max,mid,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            int result=checksum(nums,mid,n);
            if(result>threshold){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
    return ans;
    }
};