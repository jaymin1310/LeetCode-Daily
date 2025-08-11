class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            temp=s;
            reverse(temp.begin(),temp.begin()+i);
            reverse(temp.begin()+i,temp.end());
            reverse(temp.begin(),temp.end());
            if(temp==goal)return true;
        }
        return false;
    }
};