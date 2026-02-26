class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
        while(s!="1"){
            if(s.back()!='1'){
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
                s.pop_back();
                cnt++;
            }
            cnt++;
        }
        return cnt;
    }
};