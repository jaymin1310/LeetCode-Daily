class Solution {
public:
    bool possible(vector<int>&arr,int wei,int day,int n){
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>wei && i==n-1){
                cnt+=2;
            }
            else if(sum>wei || i==n-1){
                sum=arr[i];
                cnt++;
            }
        }
        return (cnt<=day);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxel=weights[0],sum=weights[0],op=0;
        for(int i=1;i<n;i++){
            maxel=max(weights[i],maxel);
            sum+=weights[i];
        }
        int low=maxel,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(weights,mid,days,n)){
                op=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return op;
    }
};