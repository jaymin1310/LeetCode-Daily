class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<pair<int,int>>occ(26,{-1,-1});
        for(int i=0;i<n;i++){
            if(occ[s[i]-'a'].first==-1){
                occ[s[i]-'a'].first=i;
            }
            occ[s[i]-'a'].second=i;
        }
        vector<pair<int,int>>range(26,{1e9,-1});
        for(int i=0;i<26;i++){
            if(occ[i].first==-1)continue;
            int l=occ[i].first,r=occ[i].second;
            bool valid=true;
            for(int j=l;j<=r;j++){
                int temp=s[j]-'a';
                if(occ[temp].first<l){
                    valid=false;
                    break;
                }
                r=max(r,occ[temp].second);
            }
            if(valid){
                range[i].first=l;
                range[i].second=r;
            }
        }
        sort(range.begin(),range.end(),[](pair<int,int>&a,pair<int,int> &b){
            return a.second<b.second;
        });
        int prev=-1;
        vector<string>ans;
        for(auto &it:range){
            if(it.second == -1) continue;
            if(it.first>prev){
                ans.push_back(s.substr(it.first,it.second-it.first+1));
                prev=it.second;
            }
        }
        return ans;
    }
};