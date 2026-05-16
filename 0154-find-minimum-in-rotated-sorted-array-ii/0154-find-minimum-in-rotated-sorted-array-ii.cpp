class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]>arr[mid]){
                ans=min(arr[mid],ans);
                high=mid-1;
            }else if(arr[low]==arr[mid]){
                ans=min(ans,arr[low]);
                for(int i=low+1;i<mid;i++){
                    if(arr[i]<arr[mid]){
                        ans=min(ans,arr[i]);
                        break;
                    }
                }
                low=mid+1;
            }
            else{
                ans=min(arr[low],ans);
                low=mid+1;
            }
        }
        return ans;
    }
};