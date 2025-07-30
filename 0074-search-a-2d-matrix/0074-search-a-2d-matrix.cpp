class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        int col=mat[0].size();
        int low=0,high=row*col,mid;
        while(low<=high){
            mid=(low+high)/2;
            int temprow=mid/col;
            int tempcol= mid%col;
            if (temprow >= row || tempcol >= col) break;
            if(mat[temprow][tempcol]==target){
                return true;
            }
            else if(mat[temprow][tempcol]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};