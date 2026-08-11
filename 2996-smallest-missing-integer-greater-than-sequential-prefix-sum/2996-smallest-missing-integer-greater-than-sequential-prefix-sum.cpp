class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=1,sum=nums[0];
        while(r<n && (nums[r]==nums[r-1]+1)){
            sum+=nums[r];
            r++;
        }
        if(sum>50)return sum;
        vector<int>pres(51,0);
        pres[nums[0]]=1;
        for(r;r<n;r++){
            pres[nums[r]]=1;
        }
        while(sum<=50){
            if(!pres[sum])break;
            sum++;
        }
        return sum;
    }
};