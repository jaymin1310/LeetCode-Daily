class Solution {
public:
    bool ispossible(vector<int>&arr,int sum,int part,int n){
        int getsum=0,div=1;
        for(int i=0;i<n;i++){
            if(getsum+arr[i]<=sum){
                getsum+=arr[i];
            }
            else{
                div++;
                getsum=arr[i];
            }
        }
        return div<=part;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=INT_MIN,high=0,mid;
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            mid=(low+high)/2;
            if(ispossible(nums,mid,k,n)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};