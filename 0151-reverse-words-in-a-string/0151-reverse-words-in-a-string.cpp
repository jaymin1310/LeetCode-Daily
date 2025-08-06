class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;

        // Step 1: Trim leading and trailing spaces
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        string temp = "", ans = "";

        while (left <= right) {
            char ch = s[left];

            if (ch != ' ') {
                temp += ch;
            } else {
                // Skip multiple spaces
                while (left <= right && s[left] == ' ') left++;

                // If temp has a word, prepend it to ans
                if (!temp.empty()) {
                    if (!ans.empty()) ans = temp + " " + ans;
                    else ans = temp;
                    temp = "";
                }

                continue; // already moved left past space
            }
            left++;
        }

        // Append the last word
        if (!temp.empty()) {
            if (!ans.empty()) ans = temp + " " + ans;
            else ans = temp;
        }

        return ans;
    }
};
