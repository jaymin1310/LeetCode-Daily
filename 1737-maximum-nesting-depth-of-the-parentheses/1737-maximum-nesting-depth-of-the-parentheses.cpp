class Solution {
public:
    int maxDepth(string s) {
        int n=s.size(),cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                ans=max(cnt,ans);
            }
            if(s[i]==')'){
                cnt--;
            }
        }
        return ans;
    }
};