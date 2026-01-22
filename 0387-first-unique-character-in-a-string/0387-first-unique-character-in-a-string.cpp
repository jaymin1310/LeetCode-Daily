class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // Count freequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find the first index with frequency = 1
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
