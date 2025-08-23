class Solution {
public:
    bool check(string& s, int n, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size(), low = -1, high = -1, cnt = 0;
        if (n == 1)
            return s;
        for (int i = 0; i < n - 1; i++) {
            int j = n - 1, res = 0;
            while (j >= i) {
            if (s[j]==s[i] && check(s, n, i, j)) {
                res = j - i + 1;
                if (res > cnt) {
                    cnt = res;
                    low = i;
                    high = j;
                }
            }
            j--;
            }
        }
        return s.substr(low, high - low + 1);
    }
};