class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        int totjum=maxJump-minJump;
        vector<int>dp(n,false);
        dp[0]=true;
        int reach=0;
        for(int i=1;i<n;i++){
            if(i-minJump>=0 && dp[i-minJump]){
                reach++;
            }
            if(i-maxJump-1>=0 && dp[i-maxJump-1]){
                reach--;
            }
            if(reach>0 && s[i]=='0')dp[i]=true;
            else dp[i]=false;
        }
        return dp[n-1];
    }
};