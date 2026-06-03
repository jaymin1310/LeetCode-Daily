class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDur, vector<int>& waterStart, vector<int>& waterDur) {
        int minDur=INT_MAX;
        int minLandDur=INT_MAX,minWaterDur=INT_MAX;
        for(int i=0;i<landStart.size();i++){
            minLandDur=min(landStart[i]+landDur[i],minLandDur);
        }
        for(int j=0;j<waterStart.size();j++){
            minDur=min(minDur,max(waterStart[j],minLandDur)+waterDur[j]);
            minWaterDur=min(waterStart[j]+waterDur[j],minWaterDur);
        }
        for(int j=0;j<landStart.size();j++){
            minDur=min(minDur,max(landStart[j],minWaterDur)+landDur[j]);
        }
        return minDur;
    }
};