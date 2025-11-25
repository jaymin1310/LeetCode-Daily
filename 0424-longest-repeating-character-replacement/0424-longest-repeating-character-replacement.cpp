class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0,r=0;
        int len=0,maxFre=0;
        int freq[26];
        while(r<n){
            freq[s[r]-'A']++;
            maxFre=max(maxFre,freq[s[r]-'A']);
            if((r-l+1-maxFre)>k){
                freq[s[l]-'A']--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};