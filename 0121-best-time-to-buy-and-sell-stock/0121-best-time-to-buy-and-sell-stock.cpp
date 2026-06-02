class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0],profit=0;
        for(auto &it:prices){
            profit=max(profit,it-minPrice);
            minPrice=min(minPrice,it);
        }
        return profit;
    }
};