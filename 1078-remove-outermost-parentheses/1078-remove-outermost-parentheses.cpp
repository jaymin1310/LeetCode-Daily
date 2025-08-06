class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int sta=0;
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(sta!=0){
                    res+=s[i];
                }
                sta++;
            }
            else{
                sta--;
                if(sta!=0){
                    res+=s[i];
                }
            }
        }
        return res;
    }
};