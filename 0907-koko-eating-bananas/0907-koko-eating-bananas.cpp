class Solution {
public:
    long long findhour(int ban,vector<int>arr,int n){
        long long total=0;
        for(int i=0;i<n;i++){
            total+=ceil((double)arr[i]/(double)ban);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mxbn = *max_element(piles.begin(), piles.end());
        int low=1,high=mxbn,mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            long long result=findhour(mid,piles,n);
            if(result<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};