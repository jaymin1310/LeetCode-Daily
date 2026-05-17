class Solution {
public:
    int recursion(vector<int>&g,vector<int>&s,int gind,int sind){
        if(gind>=g.size() || sind>=s.size())return 0;
        int res=0;
        if(g[gind]>s[sind]){
            res+=recursion(g,s,gind,sind+1);
        }else{
            res=res+1+recursion(g,s,gind+1,sind+1);
        }
        return res;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        return recursion(g,s,0,0);
    }
};