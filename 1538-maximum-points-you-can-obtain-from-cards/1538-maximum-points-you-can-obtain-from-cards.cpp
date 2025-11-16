class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int l=0,r=n;
        int sum=0;
        int maxS=0;
        for(l=0;l<k;l++){
            sum+=card[l];
        }
        maxS=sum;
        while(l>0){
            l--;
            r--;
            sum-=card[l];
            sum+=card[r];
            maxS=max(maxS,sum);
        }
        
        return maxS;
    }
};