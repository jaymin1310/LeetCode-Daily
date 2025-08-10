class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        if(n!=t.size()){
            return false;
        }
        vector<int>st(256,-1);
        vector<int>ts(256,-1);
        for(int i=0;i<n;i++){
            unsigned char ch1=s[i];
            unsigned char ch2=t[i];
            if(st[ch1]!=-1 && st[ch1]!=ch2 || ts[ch2]!=-1 && ts[ch2]!=ch1){
                return false;
            }
            st[ch1]=ch2;
            ts[ch2]=ch1;
       }
       return true;
    }
};