class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            int value;
            if(s[i]=='I')value=1;
            else if(s[i]=='V')value=5;
            else if(s[i]=='X')value=10;
            else if(s[i]=='L')value=50;
            else if(s[i]=='C')value=100;
            else if(s[i]=='D')value=500;
            else value=1000;
            temp[i]=value;
        }
        int result=temp[0];
        for(int i=1;i<n;i++){
            if(temp[i]>temp[i-1]){
                result-=(2*temp[i-1]);
            }
            result+=temp[i];
        }
        return result;
    }
};