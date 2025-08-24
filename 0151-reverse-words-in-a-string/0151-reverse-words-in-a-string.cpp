class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "", word = "";
        for (int i = n-1; i >=0; i--) {
            if (s[i] == ' ' || i == 0) {
                if (s[i] != ' ')
                    word += s[i];
                if (word.length() > 0) {
                    reverse(word.begin(), word.end());
                    if (ans.empty())
                        ans += word;
                    else {
                        ans += " " + word;
                    }
                      word = "";
                }
            } else {
                word += s[i];
            }
        }
        return ans;
    }
};