class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        int n=s.size();
        if(t.size()!=n)return false;
        for(int i=0;i<n;i++){
            auto it=mp.find(s[i]);
            if(it!=mp.end()){
                if(it->second!=t[i]){
                    return false;
                }
                continue;
            }
            mp[s[i]]=t[i];
        }
        vector<char>check;
        for(auto it:mp){
            check.push_back(it.second);
        }
        sort(check.begin(),check.end());
        for(int i=1;i<check.size();i++){
            if(check[i]==check[i-1]){
                return false;
            }
        }
        return true;
    }
};