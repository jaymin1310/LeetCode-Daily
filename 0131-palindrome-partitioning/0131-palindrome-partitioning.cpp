class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string& s, int start, vector<string>& path) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path);
                path.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return ans;
    }
};
