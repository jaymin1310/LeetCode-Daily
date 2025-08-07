class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(),ind=0;
        int strsize=strs[0].size();
        for(int i=0;i<strsize;i++){
            int cmp=strs[0][i];
        for(int j=1;j<n;j++){
            if(i>=strs[j].size() || strs[j][i]!=cmp){
                return strs[0].substr(0,ind);
            }
        }
       ind++;
        }
        return strs[0].substr(0,ind);
    }
};