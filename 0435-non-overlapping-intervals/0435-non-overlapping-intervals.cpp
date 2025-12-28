class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)return 0;
        sort(intervals.begin(),intervals.end());
        int prevstart=intervals[0][0],prevend=intervals[0][1],remove=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevend){
                remove++;
                if(intervals[i][1]<prevend){
                    prevstart=intervals[i][0];
                    prevend=intervals[i][1];
                }
            }else{
                prevstart=intervals[i][0];
                prevend=intervals[i][1];
            }
        }
        return remove;
    }
};