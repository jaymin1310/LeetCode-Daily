class Solution {
public:
    int maxDepth(string s) {
        int n=s.size(),cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};