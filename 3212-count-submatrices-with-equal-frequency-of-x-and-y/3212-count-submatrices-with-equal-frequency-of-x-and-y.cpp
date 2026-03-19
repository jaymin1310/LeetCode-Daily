class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<pair<int,int>>prevSum(n,{0,0});
        for(int i=0;i<m;i++){
            pair<int,int>currSum={0,0};
            for(int j=0;j<n;j++){
                int currChar=grid[i][j];
                currSum.first+=prevSum[j].first;
                currSum.second+=prevSum[j].second;
                if(currChar=='X'){
                    currSum.first+=1;
                    prevSum[j].first+=1;
                }else if(currChar=='Y'){
                    currSum.second+=1;
                    prevSum[j].second+=1;
                }
                if(currSum.first==currSum.second && currSum.first!=0)ans++;
            }
        }
        return ans;
    }
};