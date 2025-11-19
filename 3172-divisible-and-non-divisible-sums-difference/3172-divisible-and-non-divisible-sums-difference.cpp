class Solution {
public:
    int differenceOfSums(int n, int m) {
        // sum of 1..n
        long long total = (long long)n * (n + 1) / 2;
        // count of multiples of m in [1..n]
        long long k = n / m;
        // sum of multiples: m + 2m + ... + k*m = m * (1 + 2 + … + k) = m * (k*(k+1)/2)
        long long sumDiv = m * (k * (k + 1) / 2);
        // num1 = sum of non-divisible = total – sumDiv
        // num2 = sumDiv
        // result = num1 – num2 = (total – sumDiv) – sumDiv = total – 2*sumDiv
        long long result = total - 2 * sumDiv;
        return (int)result;
    }
};
