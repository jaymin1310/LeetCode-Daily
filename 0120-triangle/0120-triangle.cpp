class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            vector<int>temp(n,0);
            for(int j=0;j<=i;j++){
                if(j==0)temp[j]=dp[j]+triangle[i][j];
                else if(j==i)temp[j]=dp[j-1]+triangle[i][j];
                else temp[j]=min(triangle[i][j]+dp[j],triangle[i][j]+dp[j-1]);
            }
            dp=temp;
        }
        int minsum=INT_MAX;
        for(int j=0;j<triangle.size();j++){
            minsum=min(dp[j],minsum);
        }
        return minsum;
    }
};