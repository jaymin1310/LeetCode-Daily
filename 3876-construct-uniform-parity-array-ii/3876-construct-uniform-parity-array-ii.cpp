class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int oddCnt=0,smallestOdd=1e9+1,smallestEven=1e9+1;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                oddCnt++;
                smallestOdd=min(smallestOdd,nums[i]);
            }else{
                smallestEven=min(smallestEven,nums[i]);
            }
        }
        if(oddCnt==n || oddCnt==0)return true;
        return (smallestEven>smallestOdd);
    }
};