class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>tot;
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                if(!mp.count(nums[j])){
                    mp[nums[j]]++;
                    tot[nums[j]%2]++;
                }
                if(tot[0]==tot[1]){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};