class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>cons(m+1,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[j][i]){
                    cons[j+1][i]=1+cons[j][i];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            sort(cons[i].begin(),cons[i].end(),greater<int>());
            for(int j=0;j<n;j++){
                ans=max(ans,cons[i][j]*(j+1));
            }
        }
        return ans;
    }
};