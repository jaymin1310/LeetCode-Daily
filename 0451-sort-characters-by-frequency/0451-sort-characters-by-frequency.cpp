class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
       vector<pair<char,int>>temp(mp.begin(),mp.end());
       sort(temp.begin(),temp.end(),[](auto &a,auto &b){
        return a.second>b.second;
       });
       string tem;
       for(auto it:temp){
        tem.append(it.second,it.first);
       }
       return tem;

    }
};