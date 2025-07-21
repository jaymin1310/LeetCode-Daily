class Solution {
public:
    bool iselem(vector<int>&arr,int ele,int n){
        for(int i=0;i<n;i++){
            if(ele==arr[i]){
                return true;
            }
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int maxel=*max_element(arr.begin(),arr.end());
        int miss=maxel-n;
        int high,cnt=0;
        if(k>miss){
           high=maxel+(k-miss);
        }
        else{
            high=maxel;
        }
        for(int i=1;i<=high;i++){
            if(!iselem(arr,i,n)){
                cnt++;
            }
            if(cnt==k){
                return i;
            }
        }
        return -1;
    }
};