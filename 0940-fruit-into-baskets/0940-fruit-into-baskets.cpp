class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),streak=0;;
        int last=-1,seclast=-1;
        int len=0,ans=0;
        for(int i=0;i<n;i++){
            if(fruits[i]==last || fruits[i]==seclast){
                len++;
            }else{
                len=streak+1;
            }
            if(fruits[i]==last){
                streak++;
            }else{
                streak=1;
                seclast=last;
                last=fruits[i];
            }
            ans=max(ans,len);
        }
        return ans;
    }
};