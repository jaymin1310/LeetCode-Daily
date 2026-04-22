class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prevsum(n,0);
        prevsum[0]=1;
        for(int i=0;i<m;i++){
            int left=0;
            for(int j=0;j<n;j++){
                prevsum[j]=prevsum[j]+left;
                left=prevsum[j];
            }
        }
        return prevsum[n-1];
    }
};