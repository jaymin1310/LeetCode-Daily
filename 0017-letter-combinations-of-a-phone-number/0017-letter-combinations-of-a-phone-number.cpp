class Solution {
public:
    unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
    vector<string>ans;
    void recursion(int i,string& digits,string temp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string get=mp[digits[i]];
        for(char c:get){
            recursion(i+1,digits,temp+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        recursion(0,digits,"");
        return ans;
    }
};