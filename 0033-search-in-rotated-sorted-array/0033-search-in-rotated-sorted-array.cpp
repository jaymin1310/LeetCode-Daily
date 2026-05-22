class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==target)ans=i;
        }
        return ans;
    }
};