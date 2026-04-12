class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        //vector<int>dp(n+1,-1);
        int last=1,slast=0,curr;
        for(int i=2;i<=n;i++){
            curr=last+slast;
            slast=last;
            last=curr;
        }
        return last;
    }
};