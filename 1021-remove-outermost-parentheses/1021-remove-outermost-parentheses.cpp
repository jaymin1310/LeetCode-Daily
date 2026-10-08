class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size(),cnt=0;
        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt!=0){
                    res+=s[i];
                }
                cnt++;
            }else{
                if(cnt!=1){
                    res+=s[i];
                }
                cnt--;
            }
        }
        return res;
    }
};