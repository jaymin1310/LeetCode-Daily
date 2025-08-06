class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        string word="",res="";
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    res=res+word+" ";
                }
                word="";
            }
        }
        if(!word.empty()){
                    reverse(word.begin(),word.end());
                    res+=word;
        }
        if(res.back()==' '){
            res.pop_back();
        }
        return res;
    }
};