class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>rowsum(m,0);
        vector<int>colsum(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=mat[i][j];
                rowsum[i]+=temp;
                colsum[j]+=temp;
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    if(rowsum[i]==1 && colsum[j]==1)cnt++;
                }
            }
        }
        return cnt;
    }
};