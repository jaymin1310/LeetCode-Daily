class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)return 0;
        sort(intervals.begin(),intervals.end(),[](auto & a,auto & b){
            return a[1]<b[1];
        });
        int prevend=intervals[0][1],removed=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevend){
                removed++;
            }else{
                prevend=intervals[i][1];
            }
        }
        return removed;
    }
};