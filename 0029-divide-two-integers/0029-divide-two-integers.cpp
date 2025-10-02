class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        bool sign=((dividend<=0) ^ (divisor<=0))?true:false;
        long tempUp=abs((long)dividend);
        long tempDown=abs((long)divisor);
        long n=tempUp;
        long ans=0;
        while(n>=tempDown){
            int cnt=0;
            while((tempDown<<(cnt+1))<=n){
                cnt++;
            }
            ans+=1<<cnt;
            n-=(tempDown<<cnt);
        }
        return (sign)?-ans:ans;

    }
};