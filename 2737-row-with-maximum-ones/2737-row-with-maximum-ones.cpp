class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
      int row=mat.size();
      int col=mat[0].size(),ansrow=0,cnt=0;
      for(int i=0;i<row;i++){
        sort(mat[i].begin(),mat[i].end());
      }  
      for(int i=0;i<row;i++){
        int low=0,high=col-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(mat[i][mid]==1){
                if((col-mid)>cnt){
                    ansrow=i;
                    cnt=col-mid;
                }
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
      }
      return {ansrow,cnt};
    }
};