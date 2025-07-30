class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        int col=mat[0].size();
        int lowrow=0,highrow=row-1,midrow;
        while(lowrow<=highrow){
            midrow=(lowrow+highrow)/2;
            int lowcol=0,highcol=col-1,midcol,temp;
            while(lowcol<=highcol){
                midcol=(lowcol+highcol)/2;
                temp=mat[midrow][midcol];
                if(mat[midrow][midcol]==target){
                    return true;
                }
                else if(mat[midrow][midcol]>target){
                    highcol=midcol-1;
                }
                else{
                    lowcol=midcol+1;
                }
            
            }
            if(target<temp){
                highrow=midrow-1;
            }
            else{
                lowrow=midrow+1;
            }
        }
        return false;
    }
};