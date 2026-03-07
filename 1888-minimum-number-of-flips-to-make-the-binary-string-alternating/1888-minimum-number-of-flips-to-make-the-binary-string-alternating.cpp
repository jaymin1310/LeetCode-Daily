class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int diff1 = 0, diff2 = 0;
        int res = INT_MAX;

        for (int i = 0; i < 2 * n; i++) {

            char p1 = (i % 2) ? '1' : '0'; // pattern 0101
            char p2 = (i % 2) ? '0' : '1'; // pattern 1010

            if (t[i] != p1) diff1++;
            if (t[i] != p2) diff2++;

            if (i >= n) {
                char prev1 = ((i - n) % 2) ? '1' : '0';
                char prev2 = ((i - n) % 2) ? '0' : '1';

                if (t[i - n] != prev1) diff1--;
                if (t[i - n] != prev2) diff2--;
            }

            if (i >= n - 1)
                res = min(res, min(diff1, diff2));
        }

        return res;
    }
};