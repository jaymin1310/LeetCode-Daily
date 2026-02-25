class Solution {
public:
    int helper(int n){
        int cnt=0;
        while(n){
            if(n&1)cnt++;
            n=n>>1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>ans(arr.size());
        vector<int>count(15,0);
        for(int i=0;i<arr.size();i++){
            count[helper(arr[i])]++;
        }
        for(int i=1;i<15;i++){
            count[i]+=count[i-1];
        }
        for(int i=arr.size()-1;i>=0;i--){
            int bitcnt=helper(arr[i]);
            ans[count[bitcnt]-1]=arr[i];
            count[bitcnt]--;
        }
        return ans;
    }
};