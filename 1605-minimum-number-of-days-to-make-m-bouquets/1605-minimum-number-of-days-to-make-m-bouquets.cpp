class Solution {
public:
    int ispossible(vector<int>&arr,int day,int m,int k){
        int n=arr.size();
        int total=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                total++; 
                cnt=0; 
            }
        }
        if(total>=m){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=INT_MAX,high=INT_MIN,ans=-1;
        long long flow=1LL*m*k;
        if(flow>n)return ans;
        for(int i=0;i<n;i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(bloomDay,mid,m,k)==1){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};