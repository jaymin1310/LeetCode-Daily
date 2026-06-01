class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool setRow = true;
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!mat[i][j]) {
                    if(i==0){
                        setRow=false;
                    }else{
                        mat[i][0]=0;
                    }
                    mat[0][j]=0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (!mat[0][j] || !mat[i][0]) {
                    mat[i][j] = 0;
                }
            }
        }
        if (!mat[0][0]) {
            for (int i = 0; i < row; i++) {
                mat[i][0]=0;
            }
        }
        if (!setRow) {
            for (int i = 0; i < col; i++) {
                mat[0][i]=0;
            }
        }
    }
};