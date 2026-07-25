class Solution {
public:
    int maxProduct(int n) {
        int maxi=INT_MIN;
        int smaxi=INT_MIN;
        int temp=n;
        while(temp>0){
            int dig=temp%10;
            temp/=10;
            if(dig>maxi){
                smaxi=maxi;
                maxi=dig;
            }else if(dig>smaxi){
                smaxi=dig;
            }
        }
        return smaxi*maxi;
    }
};