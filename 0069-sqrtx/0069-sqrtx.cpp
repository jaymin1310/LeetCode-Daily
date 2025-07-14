class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0)return x;
       long long low=1;
       long long high=x/2,ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            if((mid*mid)<=x){
                ans=mid;
                if((mid*mid)==x){
                    return ans;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};