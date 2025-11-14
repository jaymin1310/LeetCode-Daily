#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Create a copy to store the final prices.
        vector<int> ans = prices; 
        
        // Stack to store the indices of prices that haven't found their discount yet.
        // It maintains indices such that prices[stack.top()] are in decreasing order.
        stack<int> s; 

        for (int j = 0; j < prices.size(); ++j) {
            // Check if the current price (prices[j]) is a discount for items 
            // whose indices are currently on top of the stack.
            // The condition is prices[j] <= prices[i], where i = s.top().
            while (!s.empty() && prices[j] <= prices[s.top()]) {
                int i = s.top(); // Index of the item receiving the discount
                s.pop();

                // Apply the discount: finalPrice[i] = originalPrice[i] - discountPrice[j]
                ans[i] -= prices[j];
            }
            
            // Push the current index onto the stack for future items to consider as a discount.
            s.push(j);
        }

        // Items whose indices remain in the stack did not find a discount, 
        // and their final price (already in 'ans') remains the original price.
        return ans;
    }
};