class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        vector<int>freq(256,0);
        int cnt=0;
        int maxC=0;
        while(r<s.length()){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
                cnt--;
            }
            cnt++;
            r++;
            maxC=max(cnt,maxC);
        }
        return maxC;
    }
};