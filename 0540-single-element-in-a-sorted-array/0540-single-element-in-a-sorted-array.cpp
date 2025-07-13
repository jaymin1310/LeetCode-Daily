class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==0 || mid==n-1)return arr[mid];
            if(mid%2==0){
                if(arr[mid]!=arr[mid+1]){
                    high=mid-1;
                    if(arr[mid]!=arr[mid-1]){
                        return arr[mid];
                    }
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(arr[mid]!=arr[mid+1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }

            }
        }
        return -1;
    }
};