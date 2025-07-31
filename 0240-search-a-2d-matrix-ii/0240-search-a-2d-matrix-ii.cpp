class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        int col=mat[0].size();
        int rowel=col-1,colel=0;
        while(rowel>=0 && colel<row){
            if(mat[colel][rowel]==target){
                return true;
            }
            else if(mat[colel][rowel]>target){
                rowel--;
            }
            else{
                colel++;
            }
        }
        return false;
    }
};