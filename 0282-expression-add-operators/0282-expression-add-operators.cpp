class Solution {
public:
    vector<string> ans;
    void recursion(string& nums, int i, string& exp, int target, long value,
                   long last) {
        if (i == nums.size()) {
            if (value == target) {
                ans.push_back(exp);
            }
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[i] == '0')
                break;
            string curStr = nums.substr(i, j - i + 1);
            long cur = stol(curStr);
            int len = exp.size();
            if (i == 0) {
                exp += curStr;
                recursion(nums, j + 1, exp, target, cur, cur);
                exp.resize(len);
            } else {
                exp += '+' + curStr;
                recursion(nums, j + 1, exp, target, value + cur, cur);
                exp.resize(len);
                exp += '-' + curStr;
                recursion(nums, j + 1, exp, target, value - cur, -cur);
                exp.resize(len);
                exp += '*' + curStr;
                recursion(nums, j + 1, exp, target, value - last + last * cur,
                          last * cur);
                exp.resize(len);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        string exp = "";
        recursion(num, 0, exp, target, 0,0);
        return ans;
    }
};