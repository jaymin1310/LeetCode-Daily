class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int min=INT_MAX;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<min){
                min=arr[i]-arr[i-1];
            }
        }
        vector<vector<int>>res;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==min){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};