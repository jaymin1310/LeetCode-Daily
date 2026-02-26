class Solution {
public:
    bool isEven(string s){
        if(s.back()=='1')return false;
        return true;
    }
    int numSteps(string s) {
        int cnt=0;
        while(s!="1"){
            if(isEven(s)){
                s.pop_back();
            }else{
                int carry=1,i=s.size()-1;
                while(carry && i>=0){
                    if(s[i]=='1')s[i]='0';
                    else if(s[i]=='0'){
                        s[i]='1';
                        carry=0;
                    }
                    i--;
                }
                if(carry)s='1'+s;
            }
            cnt++;
        }
        return cnt;
    }
};