class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<int> st; // keeps sums sorted and unique

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                // ---- Improvement 1: dist = 0 (single cell rhombus)
                st.insert(grid[i][j]);
                if(st.size()>3) st.erase(st.begin());

                // ---- Improvement 2: expand rhombus size
                for(int k=1;;k++){

                    int r1 = i-k, c1 = j;
                    int r2 = i,   c2 = j+k;
                    int r3 = i+k, c3 = j;
                    int r4 = i,   c4 = j-k;

                    // ---- Improvement 3: correct boundary check
                    if(r1<0 || r3>=m || c4<0 || c2>=n) break;

                    int sum = 0;

                    // ---- Improvement 4: compute 4 edges of rhombus

                    // top → right
                    for(int d=0; d<k; d++)
                        sum += grid[r1+d][c1+d];

                    // right → bottom
                    for(int d=0; d<k; d++)
                        sum += grid[r2+d][c2-d];

                    // bottom → left
                    for(int d=0; d<k; d++)
                        sum += grid[r3-d][c3-d];

                    // left → top
                    for(int d=0; d<k; d++)
                        sum += grid[r4-d][c4+d];

                    st.insert(sum);

                    // ---- Improvement 5: keep only largest 3
                    if(st.size()>3) st.erase(st.begin());
                }
            }
        }

        // ---- Improvement 6: return in descending order
        vector<int> ans(st.rbegin(), st.rend());
        return ans;
    }
};