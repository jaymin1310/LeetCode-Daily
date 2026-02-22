class Solution {
public:
    int getsetpos(int n){
        int pos=0;
        while((n&1)==0){
            pos++;
            n>>=1;
        }
        return pos;
    }
    int binaryGap(int n) {
        int right=-1,ans=0;
        while(n){
            int gap=0,curr=getsetpos(n);
            if(right!=-1){
                gap=curr-right;
                ans=max(ans,gap);
            }
            n&=(n-1);
            right=curr;
        }
        return ans;
    }
};