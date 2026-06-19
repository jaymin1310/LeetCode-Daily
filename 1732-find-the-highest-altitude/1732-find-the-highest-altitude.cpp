class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxalt=0,ans=0;
        for(auto &it:gain){
            maxalt+=it;
            ans=max(maxalt,ans);
        }
        return ans;
    }
};