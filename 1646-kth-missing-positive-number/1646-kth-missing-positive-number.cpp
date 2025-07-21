class Solution {
public:
    bool iselem(vector<int>&arr,int ele,int n,int &left){
        int flag=0;
        for(int i=0;i<n;i++){
            if(arr[i]<ele)left++;
            if(ele==arr[i]){
                flag=1;
            }
        }
        left=(ele-1)-left;
        if(flag==1)return true;
        left++;
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int maxel=*max_element(arr.begin(),arr.end());
        int miss=maxel-n;
        int low=1,mid,high,cnt=0;
        if(k>miss){
           high=maxel+(k-miss);
        }
        else{
            high=maxel;
        }
        while(low<=high){
            mid=(low+high)/2;
            int left=0;
            if(!iselem(arr,mid,n,left)){
                if(left==k){
                    return mid;
                }
                else if(left<k){
                    low=mid+1;
                }
                else{
                   high=mid-1;
                }
            }
            else{
                if(left<k){
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