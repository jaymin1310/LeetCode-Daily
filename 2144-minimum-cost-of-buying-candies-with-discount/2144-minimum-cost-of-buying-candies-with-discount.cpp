class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int candy=0,cos=0;
        for(int i=0;i<n;i++){
            if(candy==2){
                candy=0;
                continue;
            }
            cos+=cost[i];
            candy++;
        }
        return cos;
    }
};