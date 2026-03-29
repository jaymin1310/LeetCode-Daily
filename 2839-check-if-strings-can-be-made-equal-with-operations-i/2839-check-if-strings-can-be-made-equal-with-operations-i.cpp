class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string temp=s1;
        int i=0,j=2;
        for(int k=0;k<4;k++){
            swap(temp[i],temp[j]);
            if(temp==s2)return true;
            i=1-i;
            j=5-j;
        }
        return false;
    }
};