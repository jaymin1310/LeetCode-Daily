class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        for(auto &it:grid){
            for(auto &val:it){
                arr.push_back(val);
            }
        }
        sort(arr.begin(),arr.end());
        int median=arr[arr.size()/2],cnt=0;
        for(int i=0;i<arr.size();i++){
            int diff=abs(median-arr[i]);
            if(diff%x!=0)return -1;
            cnt+=diff/x;
        }
        return cnt;
    }
};