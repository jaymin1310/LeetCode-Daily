class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<int>prevsum(n,0);
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                prevsum[j]=prevsum[j]+grid[i][j];
                sum+=prevsum[j];
                if(sum<=k)ans++;
            }
        }
        return ans;
    }
};