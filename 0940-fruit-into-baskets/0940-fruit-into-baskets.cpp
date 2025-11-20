class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int first=-1,sec=-1;
        int len=0;
        int ans=len;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(fruits[i]==first || fruits[i]==sec){
                len++;
            }else if(first==-1){
                first=fruits[i];
                len++;
            }else if(sec==-1){
                sec=fruits[i];
                len++;
            }else{
                first=fruits[i-1];
                sec=fruits[i];
                len=i-ind+1;
            }
            if(ind==-1 || fruits[i]!=fruits[ind]){
                ind=i;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};