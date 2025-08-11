#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return 0;
        vector<int>mp(26,0);
        vector<int>mp2(26,0);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            mp2[t[i]-'a']++;
        }
        if(mp==mp2)return 1;
        return 0;

    }
};