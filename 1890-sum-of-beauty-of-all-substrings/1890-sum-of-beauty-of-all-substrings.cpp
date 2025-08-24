class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> arr(26, 0);
            arr[s[i] - 'a']++;
            for (int j = i + 1; j < n; j++) {
                arr[s[j] - 'a']++;
                int mincnt = INT_MAX, maxcnt = INT_MIN;
                for (int i = 0; i < 26; i++) {
                    if (arr[i] != 0) {
                        mincnt = min(arr[i], mincnt);
                        maxcnt = max(arr[i], maxcnt);
                    }
                }
                ans+=(maxcnt-mincnt);
            }
        }
        return ans;
    }
};