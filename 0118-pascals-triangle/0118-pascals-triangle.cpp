class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=vector<int>(i+1);
            temp[i][0]=1;
            int ans=1;
            for(int j=1;j<=i;j++){
                    ans=(ans*(i+1-j))/j;
                    temp[i][j]=ans;
            }
        }
        return temp;
    }
};