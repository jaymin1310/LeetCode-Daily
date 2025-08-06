class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n=s.size(),i=0;
        while(i<n){
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            while(i<n && s[i]==' '){
                i++;
            }
            if(i<n && !temp.empty())temp=" "+temp;
            res=temp+res;
        }
        return res;
    }
};