class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            bool good=false;;
            int num=i;
            while(num){
                int digit=num%10;
                num/=10;
                if(digit==2 || digit==6 || digit==9 || digit==5){
                    good=true;
                }
                if(digit==3 || digit==4 || digit==7){
                    good=false;
                    break;
                }
            }
            if(good)cnt++;
        }
        return cnt;
    }
};