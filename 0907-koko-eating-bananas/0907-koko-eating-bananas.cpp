class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1,high = *max_element(piles.begin(), piles.end()),ans;
        while(low<=high){
            long long  mid=(low+high)/2;
            long long  tt=0;
            for(int i=0;i<piles.size();i++){
                tt+=(piles[i]+mid-1)/mid;
            }
            if(tt<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};