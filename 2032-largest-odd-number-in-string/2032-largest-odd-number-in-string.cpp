class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size(),ansind=-1;
        string res="";
        for(int i=n;i>=0;i--){
            int temp=(int)num[i];
            if(temp%2!=0){
                ansind=i;
                break;
            }
        }
        if(ansind==-1)
            return res;
        for(int i=0;i<=ansind;i++){
            res+=num[i];
        }
        return res;
    }
};