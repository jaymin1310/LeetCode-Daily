class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, false);
        dp[0] = false;
        for (int rem = 1; rem <= n; rem++) {
            for (int i = 1; i * i <= rem; i++) {
                int sq = i * i;
                if (!dp[rem - sq]){
                    dp[rem] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};