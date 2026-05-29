class Solution {
public:
    int minElement(vector<int>& nums) {
        int minele=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int sum=0;
            while(temp>0){
                sum+=(temp%10);
                temp/=10;
            }
            minele=min(sum,minele);
        }
        return minele;
    }
};