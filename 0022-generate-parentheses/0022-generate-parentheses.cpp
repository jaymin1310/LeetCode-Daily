class Solution {
public:
    void recursion(vector<string>& ans, int n, string curr, int open, int close) {
        if(curr.size() == 2*n) {
            ans.push_back(curr);
            return;
        }

        if(open < n) recursion(ans, n, curr + '(', open + 1, close);
        if(close < open) recursion(ans, n, curr + ')', open, close + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(ans, n, "", 0, 0);
        return ans;
    }
};
