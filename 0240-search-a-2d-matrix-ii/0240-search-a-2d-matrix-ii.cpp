class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        int col=mat[0].size();
        for(int rowmid=0;rowmid<row;rowmid++){
            int low=0,high=col-1,mid;
            while(low<=high){
                mid=(low+high)/2;
                if(mat[rowmid][mid]==target){
                    return true;
                }
                else if(mat[rowmid][mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};