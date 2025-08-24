class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        string ans="",word="";
        for(int i=0;i<n;i++){
            if(s[i]==' ' || i==n-1){
                if(s[i]!=' ')word+=s[i];
                if(word.length()>0){
                    reverse(word.begin(),word.end());
                    ans+=" "+word;
                    word="";
                }
            }else{
                word+=s[i];
            }     
        }
        return ans.substr(1);
    }
};