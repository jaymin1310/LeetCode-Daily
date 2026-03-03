class Solution {
public:
    string invert(string s){
        string res=s;
        for(int i=0;i<res.length();i++){
            if(res[i]=='1')res[i]='0';
            else res[i]='1';
        }
        return res;
    }
    char findKthBit(int n, int k) {
        string fin="0";
        for(int i=2;i<=n;i++){
            string temp=invert(fin);
            reverse(temp.begin(),temp.end());
            fin=fin+"1"+temp;
        }
        return fin[k-1];
    }
};