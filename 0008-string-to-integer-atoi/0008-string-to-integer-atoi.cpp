class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long result=0;
        int i=0,sign=1;
            while(i<n && s[i]==' '){
                i++;
            }
            if(s[i]=='-'){sign=-1;i++;}
            else if(s[i]=='+')i++;
            while(i<n && s[i]=='0'){
                i++;
            }
            while(i<n && isdigit(s[i])){
                int digit=s[i]-'0';
                if((result>INT_MAX/10) || result==INT_MAX/10 && digit>INT_MAX%10){
                    return sign==1?INT_MAX:INT_MIN;
                }
                result=result*10+digit;
                i++;
            }
           return sign*result;
    }
};