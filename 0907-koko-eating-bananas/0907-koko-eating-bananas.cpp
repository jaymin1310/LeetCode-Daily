class Solution {
public:
    long long findhour(long long ban,vector<int>arr,int n,int h){
        long long total=0;
        for(int i=0;i<n;i++){
            total+=((arr[i]+ban-1)/ban);
            if(total>h)return total;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mxbn = *max_element(piles.begin(), piles.end());
        int low=1,high=mxbn,mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            long long result=findhour(mid,piles,n,h);
            if(result<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};