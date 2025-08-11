class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        if (n == 0) return 0;

        // Helper function to get the value of a Roman character
        auto getValue = [](char c) {
            if (c == 'I') return 1;
            if (c == 'V') return 5;
            if (c == 'X') return 10;
            if (c == 'L') return 50;
            if (c == 'C') return 100;
            if (c == 'D') return 500;
            if (c == 'M') return 1000;
            return 0;
        };

        int result = getValue(s[0]);
        int prev = result;

        for (int i = 1; i < n; i++) {
            int curr = getValue(s[i]);
            if (curr > prev) {
                result -= 2 * prev; // Subtract twice the previous value
            }
            result += curr;
            prev = curr;
        }

        return result;
    }
};