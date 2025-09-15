class Solution {
public:
    double myPow(double x, int n) {
        long long exp=n;
        if(exp==0)return 1.0;
        if(exp==1)return x;
        if(n<0){
            x=1.0/x;
            exp=-exp;
        }
        if(n%2==0)return myPow(x*x,exp/2);
        else{
           return x*myPow(x*x,exp/2);
        }
    }
};