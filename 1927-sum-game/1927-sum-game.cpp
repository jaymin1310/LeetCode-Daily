class Solution {
public:
    bool sumGame(string nums) {
        int rq=0,lq=0,n=nums.size(),diff=0;
        for(int i=0;i<(n/2);i++){
            if(isdigit(nums[i])){
                diff+=nums[i]-'0';
            }else{
                lq++;
            }
        }
        for(int i=(n/2);i<n;i++){
            if(isdigit(nums[i])){
                diff-=nums[i]-'0';
            }else{
                rq++;
            }
        }
        if((rq+lq)%2)return true;
        int target=(rq-lq)/2*9;
        return (diff!=target);
    }
};