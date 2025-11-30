class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0;
        int cnt=0,n=s.size();
        unordered_map<char,int>mp{
            {'a',0},
            {'b',0},
            {'c',0}
        };
        while(r<=n){
            if(mp['a']!=0 && mp['b']!=0 && mp['c']!=0){
                cnt+=n-r+1;
                mp[s[l]]--;
                l++;
                continue;
            }
            mp[s[r]]++;
            r++;
        }
        return cnt;
    }
};