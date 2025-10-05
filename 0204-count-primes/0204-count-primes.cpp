class Solution {
public:
    int countPrimes(int n) {
        if(n<2)return 0;
        vector<bool>mark(n,true);
        mark[0]=false;
        mark[1]=false;
        for(int i=2;i*i<=n;i++){
            if(mark[i]==true){
                for(int j=2;j*i<n;j++){
                    mark[i*j]=false;
                }
            }
        }
        return count(mark.begin(),mark.end(), true);
    }
};