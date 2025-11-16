class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        vector<int>freq(256,-1);
        int maxC=0;
        while(r<s.length()){
            if(freq[s[r]]!=-1){
                l=max(l,freq[s[r]]+1);
            }
            freq[s[r]]=r;
            maxC=max(r-l+1,maxC);
            r++;
        }
        return maxC;
    }
};