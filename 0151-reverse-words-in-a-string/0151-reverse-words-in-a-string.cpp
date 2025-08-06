class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size(), i = 0;

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            // Build current word
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            // Prepend with a space if result is not empty
            if (!temp.empty()) {
                if (!res.empty()) res = " " + res;
                res = temp + res;
            }
        }

        return res;
    }
};
