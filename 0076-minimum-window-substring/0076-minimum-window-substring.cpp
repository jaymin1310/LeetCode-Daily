class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }
        vector<int>curr(128,0);
        int cnt=t.size(),l=0;
        int minlen=INT_MAX;
        int ansl=0,ansr=0;
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]){
                curr[s[i]]++;
                if(freq[s[i]]==curr[s[i]])cnt-=freq[s[i]];
            }
            while(cnt==0){
                if(freq[s[l]]){
                    curr[s[l]]--;
                    if(curr[s[l]]<freq[s[l]]){
                        cnt+=freq[s[l]];
                        if((i-l+1)<minlen){
                            ansl=l;
                            ansr=i;
                            minlen=i-l+1;
                        }
                    }
                }
                l++;
            }   
        }
        if(minlen==INT_MAX)return "";
        return s.substr(ansl, ansr-ansl+1);
    }
};