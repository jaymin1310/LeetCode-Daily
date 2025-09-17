class Solution {
public:
    void recursion(vector<string>&ans,int n,string curr,int cnt1,int cnt2){
        if(cnt1==n && cnt1-cnt2==0){
            ans.push_back(curr);
            return;
        }
        if(cnt1!=n)recursion(ans,n,curr+'(',cnt1+1,cnt2);
        if(cnt1-cnt2!=0)recursion(ans,n,curr+')',cnt1,cnt2+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        recursion(ans,n,"(",1,0);
        return ans;
    }
};