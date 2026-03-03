class Solution {
public:
    string invert(string s){
        for(char &c:s){
            c^=1;
        }
        return s;
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