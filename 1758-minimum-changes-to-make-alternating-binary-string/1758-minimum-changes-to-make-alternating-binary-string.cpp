class Solution {
public:
    int minOperations(string s) {
        int n=s.length(),cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=((i&1)+'0')){
                cnt1++;
            }else{
                cnt2++;
            }
        } 
        return min(cnt1,cnt2);
    }
};