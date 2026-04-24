class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(j==0)dp[j]=dp[j]+triangle[i][j];
                else if(j==i)dp[j]=dp[j-1]+triangle[i][j];
                else dp[j]=min(dp[j],dp[j-1])+triangle[i][j];
            }
        }
        int minsum=INT_MAX;
        for(int j=0;j<triangle.size();j++){
            minsum=min(dp[j],minsum);
        }
        return minsum;
    }
};