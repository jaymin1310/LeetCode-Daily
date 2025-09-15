class Solution {
public:
    int recursion(string &s,int i,int result,int sign,bool started){
        if(i>=s.size()){
            return sign*result;
        }
        if(!started && s[i]==' '){
            return recursion(s,i+1,result,sign,started);
        }
        if(!started && ((s[i]=='-')||(s[i]=='+'))){
            started=true;
            sign=(s[i]=='-')?-1:1;
            return recursion(s,i+1,result,sign,started);
        }
        if(isdigit(s[i])){
            started=true;
            int digit=s[i]-'0';
            if((result>INT_MAX/10) || (result==INT_MAX/10 && digit>INT_MAX%10)){
                return (sign==1)?INT_MAX:INT_MIN;
            }
            result=(result*10)+digit;
            return recursion(s,i+1,result,sign,started);
        }
        return sign* result;
    }
    int myAtoi(string s) {
        int result=0;
        int sign=1;
        return recursion(s,0,result,sign,false);
    }
};