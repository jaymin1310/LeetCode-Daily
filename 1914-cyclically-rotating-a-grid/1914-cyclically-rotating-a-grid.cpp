class Solution {
public:
    void rotateByK(vector<int>&arr,int k){
        int n=arr.size();
        k%=n;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+n-k);
        reverse(arr.begin()+n-k,arr.end());
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> layer;
        int m = grid.size(), n = grid[0].size();
        int top = 0, left = 0, right = n - 1, bottom = m - 1;
        while (left <= right && top <= bottom) {
            vector<int> templay;
            for (int i = left; i <= right; i++) {
                templay.push_back(grid[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                templay.push_back(grid[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    templay.push_back(grid[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    templay.push_back(grid[i][left]);
                }
                left++;
            }
            layer.push_back(templay);
        }
        for(auto &it:layer){
            rotateByK(it,k);
        }
        vector<vector<int>>ans(m,vector<int>(n));
        top = 0, left = 0, right = n - 1, bottom = m - 1;
        for(auto &it:layer){
            int ind=0;
            for (int i = left; i <= right; i++) {
                ans[top][i]=it[ind++];
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans[i][right]=it[ind++];
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i]=it[ind++];
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left]=it[ind++];
                }
                left++;
            }
        }
        return ans;
    }
};