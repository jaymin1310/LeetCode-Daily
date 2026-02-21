class Solution {
public:
    bool isPrime(int cnt) {
        return (cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 ||
                cnt == 13 || cnt == 17 || cnt == 19);
    }
    int cntsetbits(int n){
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int tot=0;
        for(int i=left;i<=right;i++){
            int setbits=cntsetbits(i);
            if(isPrime(setbits))tot++;
        }
        return tot;
    }
};