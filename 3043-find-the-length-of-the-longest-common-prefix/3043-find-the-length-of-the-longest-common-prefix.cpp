class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        string ans="";
        for(auto &it:arr1){
            string temp="";
            string numstr= to_string(it);
            for(int i=0;i<numstr.size();i++){
                temp+=numstr[i];
                mp[temp]++;
            }
        }
        for(auto &it:arr2){
            string temp="";
            string numstr=to_string(it);
            for(int i=0;i<numstr.size();i++){
                temp+=numstr[i];
                if(mp.find(temp)!=mp.end()){
                    if(ans.size()<temp.size()){
                        ans=temp;
                    }
                }

            }
        }
        return ans.size();
    }
};