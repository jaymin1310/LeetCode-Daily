class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        int last=1,slast=1;
        for(int i=2;i<=n;i++){
            int curr=last+slast;
            slast=last;
            last=curr;
        }
        return last;
    }
};