class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        string ans, word;

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    reverse(word.begin(), word.end());
                    if (!ans.empty()) ans += " ";
                    ans += word;
                    word.clear();
                }
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            if (!ans.empty()) ans += " ";
            ans += word;
        }
        return ans;
    }
};
