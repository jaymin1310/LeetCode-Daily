class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int strsize=strs[0].size();
        string res="";
        for(int i=0;i<strsize;i++){
            int cmp=strs[0][i];
            int flag=0;
        for(int j=1;j<n;j++){
            if(i>=strs[j].size() || strs[j][i]!=cmp){
                flag=1;
            }
        }
        if(flag==0){
            res+=cmp;
        }
        else{
            break;
        }
        }
        return res;
    }
};