class Solution {
public:
    string helper(int i,int n,int k,string temp,int &cnt,char last){
        if(i>=n){
            cnt++;
            if(cnt==k){
                return temp;
            }
            else{
                return "";
            }

        }
        string a,b,c;
        if(last!='a')a=helper(i+1,n,k,temp+'a',cnt,'a');
        if(last!='b')b=helper(i+1,n,k,temp+'b',cnt,'b');
        if(last!='c')c=helper(i+1,n,k,temp+'c',cnt,'c');
        if(a!="")return a;
        else if(b!="")return b;
        return c;
    }

    string getHappyString(int n, int k) {
        int cnt=0;
        return helper(0,n,k,"",cnt,'\0');
    }
};