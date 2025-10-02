class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;

        // Determine sign
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Work with positive long long
        long long a = std::abs((long long)dividend);
        long long b = std::abs((long long)divisor);

        // Base case
        if (a < b) return 0;

        int cnt = 0;
        while ((b << (cnt + 1)) <= a) {
            cnt++;
        }

        long long quot = 1LL << cnt;
        long long rem = a - (b << cnt);

        return sign * (quot + divide(rem, b)); // pass positive divisor
    }
};
