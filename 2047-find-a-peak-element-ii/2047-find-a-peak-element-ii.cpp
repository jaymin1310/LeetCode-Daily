class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int low=0,high=col-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            int tmpr,ans=INT_MIN;
            for(int i=0;i<row;i++){
                if(mat[i][mid]>ans){
                    ans=mat[i][mid];
                    tmpr=i;
                }
            }
            int left=-1,right=-1;
            if(mid!=0){
                left=mat[tmpr][mid-1];
            }
            if(mid!=col-1){
                right=mat[tmpr][mid+1];
            }
            if(mat[tmpr][mid]>left && mat[tmpr][mid]>right){
                return {tmpr,mid};
            }
            else if(mat[tmpr][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return{-1,-1};
    }
};