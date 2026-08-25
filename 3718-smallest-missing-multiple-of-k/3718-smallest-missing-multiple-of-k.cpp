class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int tot=k;
        for(int &it:nums){
            if(!(it%k))mp[it]=1;
        }
        while(true){
            if(mp.find(tot)==mp.end()){
                return tot;
            }
            tot+=k;
        }
        return -1;
    }
};