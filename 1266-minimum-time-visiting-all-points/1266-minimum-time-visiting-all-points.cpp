class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        for(int i=1;i<n;i++){
            int dx=abs(points[i][0]-points[i-1][0]);
            int dy=abs(points[i][1]-points[i-1][1]);
            if(dx==dy){
                ans+=dx;
                continue;
            }
            ans+=min(dx,dy);
            ans+=max(dx,dy)-min(dx,dy);
        }
        return ans;
    }
};