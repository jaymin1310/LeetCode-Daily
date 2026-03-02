class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> mostpos(m, -1);
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    mostpos[i] = j;
                    break;
                }
            }
        }
        int cnt = 0;
        for (int j = 0; j < m-1; j++) {
            int req=j;
            int flag=0;
            for (int i = j; i < m; i++) {
                if (mostpos[i] <= req) {
                    cnt+=i-j;
                    flag=1;
                    for(int k=i;k>j;k--){
                        swap(mostpos[k],mostpos[k-1]);
                    }
                    break;
                }
            }
            if(!flag)return -1;
        }
        return cnt;
    }
};