class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)return 0;
        sort(intervals.begin(),intervals.end());
        int prevstart=intervals[0][0],prevend=intervals[0][1],remove=0;
        for(int i=1;i<n;i++){
            int curstart=intervals[i][0];
            int curend=intervals[i][1];
            if(curstart<prevend){
                remove++;
                if(curend<prevend){
                    prevstart=curstart;
                    prevend=curend;
                }
            }else{
                prevstart=curstart;
                prevend=curend;
            }
        }
        return remove;
    }
};