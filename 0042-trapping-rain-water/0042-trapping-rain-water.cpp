class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        suffix[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            suffix[n-1-i]=max(suffix[n-i],height[n-1-i]);
        }
        int res=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(height[i],maxi);
            if(height[i]<maxi && height[i]<suffix[i]){
                res+=min(maxi,suffix[i])-(height[i]);
            }
        }
        return res;
    }
};