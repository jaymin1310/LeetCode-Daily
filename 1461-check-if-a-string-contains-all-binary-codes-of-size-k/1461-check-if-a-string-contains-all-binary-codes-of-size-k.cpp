class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        int total=1<<k;
        int mask=total-1;
        vector<int>mark(total,0);
        int hash=0;
        for(int i=0;i<n;i++){
            hash=((hash<<1)&mask)|s[i]-'0';
            if(i>=k-1){
                mark[hash]=1;
            }
        }for(int i=0;i<total;i++){
            if(!mark[i])return false;
        }
        return true;
    }
};