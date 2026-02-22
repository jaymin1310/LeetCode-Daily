class Solution {
public:
    int binaryGap(int n) {
    int right = -1, ans = 0;

    while(n) {
        int curr = __builtin_ctz(n);

        if(right != -1) {
            ans = max(ans, curr - right);
        }

        right = curr;
        n &= (n - 1);
    }

    return ans;
}
};