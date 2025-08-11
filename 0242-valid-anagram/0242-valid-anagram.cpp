#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return 0;
        vector<int>mp(26,0);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(int cnt:mp){
            if(cnt!=0)return 0;
        }
        return 1;

    }
};