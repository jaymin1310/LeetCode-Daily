class Solution {
public:
    const long long MOD=1e9+7;
    long long myPow(long long x, long long n) {
        if(n==0)return 1.0;
        if(n==1)return (x % MOD);
        long long half=myPow(x,n/2);
        long long result=(half*half)%MOD;
        if(n%2==1){
           result=(result*(x % MOD)%MOD);
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = myPow(5, (n+1)/2);   // ceil(n/2)
        long long odd  = myPow(4, n/2);       // floor(n/2)
        return (even * odd) % MOD;

    }
};